#include "Header.hpp"

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
    virtual void Run()
    {

    }

    virtual ~Task()
    {

    }
  private:
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

class MyTask : public Task
{
  public:
    MyTask(int id)
    {
      _id = id;
    }

    virtual void Run()
    {
      printf("id = %d\n",_id);
    }
  private:
    int _id;
};
int main()
{
  ThreadPool* pool = new ThreadPool(10);
  for(int i = 0;i < 20;i++)
  {
    pool->AddTask(new MyTask(i));
  }
  while(1)
  {
    sleep(1);
  }
  delete pool;
  return 0;
}
