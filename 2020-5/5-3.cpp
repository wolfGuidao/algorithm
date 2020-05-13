#include "Header.hpp"

template<class T>
class UniquePtr
{
  public:
    UniquePtr(T * ptr = nullptr)
      : _ptr(ptr)
    {}

    ~UniquePtr()
    {
      if(_ptr)
        delete _ptr;
    }

    UniquePtr(UniquePtr<T> && sp)
    {
      swap(sp._ptr,_ptr);
    }

    UniquePtr& operator=(UniquePtr<T> && sp)
    {
      if(this != &sp)
      {
        swap(sp._ptr,_ptr);
      }
      return *this;
    }

    T& operator*() {return *_ptr;}

    T* operator->() {return _ptr;}

  private:
    UniquePtr(UniquePtr<T> const &) = delete;
    UniquePtr& operator=(UniquePtr<T> const &) = delete;

  private:
    T * _ptr;
};

int main()
{
  UniquePtr<int> ptr1(new int(1));
  cout<<*ptr1<<endl;
  UniquePtr<int> ptr2;
  //ptr2 = ptr1;
  //UniquePtr<int> ptr3(ptr1);
  //UniquePtr<int> ptr4 = std::move(ptr1); 
  UniquePtr<int> ptr4(std::move(ptr1));
  cout<<*ptr4<<endl;
  //unique_ptr<int> ptr4(new int(999));
  //unique_ptr<int> ptr5 = std::move(ptr4);
  //cout<<*ptr5<<endl;
  return 0;
}
