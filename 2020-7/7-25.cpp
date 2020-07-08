/*************************************************************************
  > File Name: 7-25.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月07日 星期二 15时28分38秒
 ************************************************************************/

#include "Header.hpp"

static int a = 999;

void Func()
{
    static int b;
    cout<<b<<endl;
}

class A 
{
    public:
        A()
        {

        }

    static void GetB(A aa)
    {
        cout<<aa.b<<endl;
    }
    public:
        static int a;
        int b = 666;
};
int A::a = 999;

void TestDeque()
{
    //deque<int> deq;
    list<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    cout<<deq.size()<<endl;

    auto it = deq.begin();
    while(it != deq.end())
    {
        //it = deq.erase(it);
        deq.erase(it++);
    }
    cout<<deq.size()<<endl;
}

int main()
{
    //static int a;
    //for(auto i = 0;i < 10;i++)
    //{
    //    a += i;
    //    cout<<a<<endl;
    //}
    //cout<<a<<endl;
    //Func();
    
    TestDeque();
    return 0;
}

