#pragma once 
#include "tcp_socket.hpp"
typedef function<void(const string& req,string* resp)>Handler;

struct SockArg
{
  string ip;
  uint16_t port;
  TcpSocket sock;
  Handler handler;
};

template<class T>
class BlockQueue 
{
  public:
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

    ~BlockQueue()
    {
      sem_destroy(&_lock);
      sem_destroy(&_Product);
      sem_destroy(&_Consume);
    }

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
    vector<T> _queue;
    int _head;
    int _tail;
    int _size;
    int _max_size;

    sem_t _lock;

    sem_t _Consume;

    sem_t _Product;
};

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

class MyTask : public Task
{
  public:
    MyTask(SockArg arg_)
      :_arg(arg_)
    {


    }

    virtual void Run()
    {
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
class ThreadPool
{
  public:
    ThreadPool(int ThreadCount)
      :_queue(100)
       ,_work_thread_count(ThreadCount)
       ,_vec(ThreadCount)
  {
    for(int i = 0;i < ThreadCount;i++)
    {
      pthread_create(&_vec[i],NULL,ThreadEntry,(void*)this);
    }
  }
    ~ThreadPool()
    {
      for(int i = 0;i < _work_thread_count;i++)
      {
        pthread_cancel(_vec[i]);
      }
      for(int i = 0;i < _work_thread_count;i++)
      {
        pthread_join(_vec[i],NULL);
      }
    }

    void AddTask(Task* task)
    {
      _queue.Push(task);
    }

    static void* ThreadEntry(void* arg)
    {
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
    BlockQueue<Task*> _queue;
    int _work_thread_count;
    vector<pthread_t> _vec;
};

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
