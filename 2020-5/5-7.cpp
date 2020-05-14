#include "Header.hpp"

//class Singleton
//{
//  public:
//    static Singleton* GetSingleton()
//    {
//      return &_singleton;
//    }
//
//  private:
//    Singleton(){};
//    Singleton(const Singleton&);
//    Singleton& operator=(const Singleton&);
//
//    static Singleton _singleton;
//};
//Singleton Singleton::_singleton;

class Singleton 
{
  public:
   static Singleton* GetSingleton()
   {
     if(_singleton == nullptr)
     {
       _mutex.lock();
       if(_singleton == nullptr)
       {  
          _singleton = new Singleton();
       }
       _mutex.unlock();
     }
     return _singleton;
   }

  private:
    Singleton(){};

    Singleton(const Singleton&);

    Singleton& operator=(const Singleton&);

    static Singleton* _singleton;
    static mutex _mutex;
};

Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mutex;

int main()
{
  Singleton* s1 = Singleton::GetSingleton();
  cout<<s1<<endl;
  return 0;
}
