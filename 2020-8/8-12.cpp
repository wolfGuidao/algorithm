/*************************************************************************
# File Name: 8-12.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月29日 星期三 13时40分29秒
*************************************************************************/

#include <iostream>
using namespace std;

class A 
{
    public:
    virtual void Print(int a = 999)
    {
        cout<<a<<endl;
    }
};

class B : public A 
{
    public:
    virtual void Print(int a = 666)
    {
        cout<<a<<endl;
    }
};

void Test(A& a)
{
    a.Print();
}

int main()
{
    B b;
    Test(b);
    return 0;
}
