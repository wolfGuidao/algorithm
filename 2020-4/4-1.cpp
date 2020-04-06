#include "Header.hpp"
using namespace std;

//饿汉式
#if 0
class Singleton
{
  public:
    static Singleton* GetINstance()
    {
      return &instance;
    }

  private:
    Singleton()
    {}

    Singleton(const Singleton&);
    Singleton& operator= (const Singleton&);

    static Singleton instance;
};

Singleton Singleton::instance;
#endif

class Singleton
{
  public:
    static Singleton* GetInstance()
    {
      if(instance == nullptr)
      {
        pthread_mutex_lock(&_mutex);
        if(instance == nullptr)
        {
          instance = new Singleton();
        }
        pthread_mutex_unlock(&_mutex);
      }
      return instance;
    }
  private:
    //把构造函数/拷贝构造函数、赋值运算符重载并设为私有
    Singleton()
    {
      cout<<"i am Singleton()"<<endl;
    }
    ~Singleton()
    {
      cout<<"i am ~Singleton()"<<endl;
    }

    Singleton(const Singleton&);
    Singleton& operator= (const Singleton&);

  public:
    class CGarbo
    {
      public:
        ~CGarbo ()
        {
          if(instance)
          {
            cout<<"i am ~CGarbo()"<<endl;
            delete Singleton::instance;
          }
        }

    };
  private:
    //内嵌垃圾回收类
    static CGarbo cgarbo;
    //单例
    static Singleton* instance;
    //锁
    static pthread_mutex_t _mutex;
};

Singleton::CGarbo cgarbo;
Singleton* Singleton::instance = nullptr;
pthread_mutex_t Singleton::_mutex;

int main() 
{
  //Singleton* s = Singleton::GetInstance();
  return 0;
}
