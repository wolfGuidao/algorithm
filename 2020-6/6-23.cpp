/*************************************************************************
  > File Name: 6-23.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月12日 星期五 10时25分41秒
 ************************************************************************/

#include "Header.hpp"

#if 0
int g_val = 100;
struct ARG; 

void Handler(int sig)
{
  cout<<"i catch a sig:"<<sig<<endl;
}

void* ThreadEntry(void* arg)
{
  pthread_t tid = *(pthread_t*)arg;
  pthread_detach(tid);
  cout<<"i am pthread"<<endl;
  return nullptr;
}

void* ThreadEntry1(void* arg)
{
  ARG args = *(ARG*)arg;
  while(1)
  {
    //pthread_mutex_lock(mutex);
    g_val--;
    pthread_cond_signal(args->cond);
    //pthread_mutex_unlock(mutex);
    cout<<"i am pthread1, i am ++g_val,g_val: "<<g_val<<endl;
    //sleep(2);
  }
  return nullptr;
}

void* ThreadEntry2(void* arg)
{
  ARG* args = (ARG*)arg;
  while(1)
  {
    //pthread_mutex_lock(mutex);
    g_val--;
    //pthread_mutex_unlock(mutex);
    cout<<"i am pthread2, i am --g_val,g_val: "<<g_val<<endl;
    //sleep(2);
  }
  return nullptr;
}

int main()
{
  //signal(2,Handler);
  //signal(2,SIG_IGN);
  //struct sigaction newac;
  //struct sigaction oldac;
  //newac.sa_handler = Handler;
  //sigaction(2,&newac,nullptr);

  //sigset_t set;
  //sigemptyset(&set);
  ////sigfillset(&set);
  //sigaddset(&set,2);
  //sigaddset(&set,40);
  //sigprocmask(SIG_BLOCK,&set,nullptr);

  //struct sigaction sigset;
  //sigset.sa_handler = Handler;
  //sigaction(2,&sigset,nullptr);
  //sigaction(40,&sigset,nullptr);
  //sleep(20);
  //sigprocmask(SIG_UNBLOCK,&set,nullptr);

  //pthread_t tid;
  //pthread_attr_t attr;
  //pthread_attr_init(&attr);
  //size_t stacksize;
  //pthread_create(&tid,&attr,ThreadEntry,(void*)&tid);
  //pthread_attr_getstacksize(&attr,&stacksize);
  //cout<<stacksize;
  ////pthread_join(tid,nullptr);
  //sleep(3);

  pthread_t tid[2];
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  pthread_mutex_init(&mutex,nullptr);
  pthread_cond_init(&cond,nullptr);

  struct ARG 
  {
    ARG(pthread_mutex_t _Mutex,pthread_cond_t _Cond)
    {
      mutex = _Mutex;
      cond = _Cond;
    }
    pthread_mutex_t mutex;
    pthread_cond_t cond;
  };

  ARG arg(mutex,cond);

  pthread_create(&tid[0],nullptr,ThreadEntry1,&arg);
  pthread_create(&tid[0],nullptr,ThreadEntry2,&arg);

  while(1);

  pthread_join(tid[0],nullptr);
  pthread_join(tid[1],nullptr);
  return 0;
}
#endif

int g_val = 999;

class TestThread 
{
  public:
    TestThread(pthread_mutex_t Mutex,pthread_cond_t Cond)
      :_mutex(Mutex)
       ,_cond(Cond)
  {
    pthread_mutex_init(&_mutex,nullptr);
    pthread_cond_init(&_cond,nullptr);
  }

    static void* ThreadEntry1(void* arg)
    {
      (void)arg;
      while(1)
      {
        pthread_mutex_lock(&_mutex);
        g_val++;
        pthread_mutex_unlock(&_mutex);
      }
      return nullptr;
    }

    ~TestThread()
    {
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond);
    }

  private:
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
};

int main()
{
  return 0;
}
