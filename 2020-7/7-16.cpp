/*************************************************************************
  > File Name: 7-16.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月02日 星期四 17时11分32秒
 ************************************************************************/

#include "Header.hpp"
#include "test.h"
#include <cstdarg>

class A 
{
    private:
        int a;
        int b;
    public:
        A(int aa,int bb)
            :a(aa)
             ,b(bb)
    {}
        template<class T>
            void func(const T&){};

        void GetA()
        {
            cout<<" a : "<<a<<endl;
        }

        void GetB()
        {
            cout<<" b : "<<b<<endl;
        }

        friend void Print(A& a);
};

void Print(A& a)
{
    cout<<"a: "<<a.a<<" b: "<<a.b<<endl;
}

class B  
{};

template<> 
void A::func(const B&)
{
    a = 666;
    b = 999;
}

//extern int ret;

int main()
{
    A a(1,2);
    a.GetA();
    a.GetB();

    B b;
    a.func(b);
    a.GetA();
    a.GetB();

    cout<<ret<<endl;
    cout<<wolf<<endl;
    
    Print(a);

    co

    return 0;
}

