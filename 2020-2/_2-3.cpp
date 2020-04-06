#include "Header.hpp"
//不用+/- ......求1 + 2 + ... + n的和
//方法一：利用构造函数的特性
class A
{
  public:
    A()
    {
      count++;
      sum += count;
    }
    static long long sum;
    static long long count;
};

long long A::sum = 0;
long long A::count = 0;


void Sum1(int n)
{
  A* a = new A[n];
  (void)a;
  cout<<" sum : "<<A::sum<<endl;
}

//方法二：利用非类型模板参数
template<int N>
long long Sum()
{
  return N + Sum<N - 1>();
}

template<>
long long Sum<1>()
{
  return 1;
}

void Sum2()
{
  cout<<" sum : "<<Sum<5>()<<endl;
}

//方法三：利用多态

class B;
class C;
B* arr[2];
class B
{
  public:
  virtual long long Sum(int n)
  {
    return 0;
  }
};

class C : public B
{
  public:
  virtual long long Sum(int n)
  {
    //当n不为0时，arr[!!n]一直都是arr[1]，代表一直调用的是派生类的函数，一旦n==0时，
    //调用的是arr[0]即基类的Sum
    return arr[!!n]->Sum(n - 1) + n;
  }
};

void Sum3(int n)
{
  B b;
  C c;
  arr[0] = &b;
  arr[1] = &c;
  //用基类的指针指向派生类构成多态,先调用派生类的Sum函数
  cout<<" sum : "<<arr[1]->Sum(n)<<endl;
}

//方法四：短路计算模拟递归
int  sum4(int n)
{
  int ret = n;
  //当n不等于0时，下面的代码才进行&&的右边代码，进行递归运算；当n==0时，下面代码是不会执行&&的右边的递归代码
  //简单的模拟递归,n==0就是递归出口
  n && (ret += sum4(n - 1));
  return ret;
}

void Sum4(int n)
{
  cout<<" sum : "<<sum4(n)<<endl;
}

int main()
{
  Sum1(5);
  Sum2();
  Sum3(5);
  Sum4(5);
}
