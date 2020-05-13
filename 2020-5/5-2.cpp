#include "Header.hpp"

template<class T>
class SharedPtr 
{
  public:
    SharedPtr(T* ptr = nullptr)
      :_mutex(new mutex)
       ,_count(new int(1))
       ,_ptr(ptr)
  {

  }

    SharedPtr(const SharedPtr<T>& sp)
    :_mutex(sp._mutex)
     ,_count(sp._count)
     ,_ptr(sp._ptr)
    {
      AddCount();
    }

    SharedPtr operator=(const SharedPtr<T>& sp)
    {
      if(this != &sp)
      {
        Release();
        _mutex = sp._mutex;
        _count = sp._count;
        _ptr = sp._ptr;
        AddCount();
      }
      return *this;
    }

    T& operator*()
    {
      return *_ptr;
    }

    T* operator->()
    {
      return _ptr;
    }

    ~SharedPtr()
    {
      Release();
    }

    size_t UserCount()
    {
      return *_count;
    }

  private:
    void AddCount()
    {
      _mutex->lock();
      (*_count)++;
      _mutex->unlock();
    }


    void Release()
    {
      bool flag = false;

      _mutex->lock();
      if(--(*_count) == 0)
      {
        delete _ptr;
        delete _count;
        flag = true;
      }
      _mutex->unlock();

      if(flag)
      {
        delete _mutex;
      }
    }


    mutex* _mutex;
    int* _count;
    T* _ptr;
};

int main()
{
  SharedPtr<int> sp1(new int(10));
  cout<<sp1.UserCount()<<endl;
  SharedPtr<int> sp2;
  cout<<sp2.UserCount()<<endl;
  sp2 = sp1;
  cout<<sp1.UserCount()<<endl;
  cout<<sp2.UserCount()<<endl;
  SharedPtr<int> sp3(sp1);
  cout<<sp1.UserCount()<<endl;
  SharedPtr<int> sp4(new int(10));
  cout<<sp1.UserCount()<<endl;
  SharedPtr<int> sp5(new int(10));
  cout<<sp1.UserCount()<<endl;
  return 0;
}
