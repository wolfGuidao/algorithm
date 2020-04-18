#pragma once 
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)>Handler;

//用结构体保存相关信息，用来传给线程池的任务类
struct SockArg
{
  string ip;
  uint16_t port;
  TcpSocket sock;
  Handler handler;
};

//线程安全的任务队列
template<class T>
class BlockQueue 
{
  public:
    //初始化
    BlockQueue(int max_size)
      :_max_size(max_size)
       ,_head(0)
       ,_tail(0)
       ,_size(0)
       ,_queue(max_size)
  {
    sem_init(&_lock,0,1);

    sem_init(&_Product,0,max_size);

    sem_init(&_Consume,0,0);
  }

    //销毁
    ~BlockQueue()
    {
      sem_destroy(&_lock);
      sem_destroy(&_Product);
      sem_destroy(&_Consume);
    }

    //往任务队列放任务
    void Push(const T& data)
    {
      sem_wait(&_Product);

      sem_wait(&_lock);
      _queue[_tail] = data;
      _tail++;
      _size++;
      sem_post(&_lock);

      sem_post(&_Consume);
    }

    //从任务队列取任务
    void Pop(T* data)
    {
      sem_wait(&_Consume);

      sem_wait(&_lock);
      *data = _queue[_head];
      _head++;
      _size--;
      sem_post(&_lock);

      sem_post(&_Product);
    }

  private:
    //任务队列
    vector<T> _queue;

    //指向任务队列的开始
    int _head;

    //指向任务队列的结尾
    int _tail;

    //当前任务队列的数量
    int _size;

    //最大的任务数量
    int _max_size;

    //用信号量实现互斥
    sem_t _lock;

    //用信号量实现同步
    sem_t _Consume;

    sem_t _Product;
};

//创建线程池时往任务队列中放的任务，采用多态的形式实现

class Task 
{
  public:
    Task()
    {

    }

    Task(SockArg _arg)
    {
      arg = _arg; 
    }

    virtual void Run()
    {

    }

    virtual ~Task()
    {

    }
  private:
    SockArg arg;
};

//用户自己重写任务队列
class MyTask : public Task
{
  public:
    MyTask(SockArg arg_)
      :_arg(arg_)
    {


    }

    //代表从任务对列去出任务的执行逻辑
    //我们往任务队列中放的是已经建立连接的用户ip信息
    virtual void Run()
    {
      //直接拿ip信息进行手法数据
      while(1)
      {
        string req;
        int ret = _arg.sock.Recv(&req);
        if(ret < 0)
        {
          continue;
        }
        if(ret == 0)
        {
          printf("有客户端断开连接！ip:[%s],port[%d]\n",_arg.ip.c_str(),_arg.port);
          return ;
        }
        string resp;
        _arg.handler(req,&resp);
        _arg.sock.Send(resp);
      }
    }
  private:
    SockArg _arg;

};

//线程池
class ThreadPool
{
  public:
    ThreadPool(int ThreadCount)
      :_queue(100)
       ,_work_thread_count(ThreadCount)
       ,_vec(ThreadCount)
  {
    //创建线程
    for(int i = 0;i < ThreadCount;i++)
    {
      pthread_create(&_vec[i],NULL,ThreadEntry,(void*)this);
    }
  }
    ~ThreadPool()
    {
      //先终止再回收线程
      for(int i = 0;i < _work_thread_count;i++)
      {
        pthread_cancel(_vec[i]);
      }
      for(int i = 0;i < _work_thread_count;i++)
      {
        pthread_join(_vec[i],NULL);
      }
    }

    //向线程安全的任务队列放任务
    void AddTask(Task* task)
    {
      _queue.Push(task);
    }

    //线程入口函数
    static void* ThreadEntry(void* arg)
    {
      //每个线程从任务队列中取任务并执行
      ThreadPool* pool = (ThreadPool*)arg;
      while(1)
      {
        Task* task;
        pool->_queue.Pop(&task);
        task->Run();
      }
      return NULL;
    }
  private:
    //线程安全的任务队列
    BlockQueue<Task*> _queue;
    //工作线程的数量
    int _work_thread_count;
    //用来存放创建线程的tid方便回收
    vector<pthread_t> _vec;
};

//服务端
class TcpPoolServer 
{
  public:
    TcpPoolServer()
      :_pool(10)
    {
      _sock.Socket();
    }

    ~TcpPoolServer()
    {
      _sock.Close();
    }

    bool Start(const string& ip,const uint16_t& port,Handler handler)
    {
      _sock.Bind(ip,port);

      _sock.Listen(5);

      while(1)
      {
        TcpSocket newsock;
        string _ip;
        uint16_t _port;

        _sock.Accept(&newsock,&_ip,&_port);
        printf("有客户端成功链接! ip:[%s],port:[%d]\n",_ip.c_str(),_port);

        //把成功链接进来的用户ip信息放到任务队列当中
        SockArg* arg = new SockArg();
        arg->handler = handler;
        arg->ip = _ip;
        arg->port = _port;
        arg->sock = newsock;
        MyTask* task = new MyTask(*arg);

        _pool.AddTask(task);
      }
    }
  private:
    ThreadPool _pool;
    TcpSocket _sock;
};
