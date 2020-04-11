#include "Header.hpp"

#if 0
class A
{
  public:
    A()
    {
      cout<<"i am A ()"<<endl;
    }
};

A a;

int main()
{
  printf("i am main\n");
  return 0;
}

#endif 

#if 1
void Func(int& a)
{
  cout << "i am int&"<<endl;
}
void Func(const int& a)
{
  cout<<"i am const int&"<<endl;
}
void Func(int&& a)
{
  cout<<"i am int&&"<<endl;
}
void Func(const int&& a)
{
  cout<<"i am const int&&"<<endl;
}

template <class T>
void Test(T&& a)
{
  Func(forward<T>(a));
}

int main()
{
  int a = 1;
  const int b = 1;
  Test(1);
  Test(a);
  Test(b);
  Test(std::move(a));
  return 0;
}
#endif 

#if 0
void Fun(int &x){cout << "lvalue ref" << endl;}
void Fun(int &&x){cout << "rvalue ref" << endl;}
void Fun(const int &x){cout << "const lvalue ref" << endl;}
void Fun(const int &&x){cout << "const rvalue ref" << endl;}
template<typename T>
void PerfectForward(T &&t){Fun(std::forward<T>(t));}
int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}
#endif 
