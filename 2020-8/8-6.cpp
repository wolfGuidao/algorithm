/*************************************************************************
# File Name: 8-6.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月18日 星期六 21时07分41秒
 *************************************************************************/

#include <iostream>
#include <unistd.h>
using namespace std;
using INT = int;

void* ThreadEntry(void* arg)
{
    (void)arg;
    while(1)
    {
        cout<<"i am child thread"<<endl;
        sleep(1);

    }
}
#pragma pack(8)
struct Num 
{
    char c;
    char a;
    int b;
    int* d;
};

static int a = 999;
#include <deque>
#include <map>
#include <set>
#include <list>

int main()
{
    //pthread_t tid;
    //pthread_create(&tid,nullptr,ThreadEntry,nullptr);
    ////pthread_join(tid,nullptr);
    //static int a = 666;
    //cout<<a<<endl;
    //set<int> arr{1,2,3,4,5,56,7,8};
    //for(auto e : arr)
    //{
    //    cout<<e<<" ";
    //}
    //cout<<endl;

    //auto it = arr.begin();
    //while(it != arr.end())
    //{
    //    it = arr.erase(it);
    //}
    //cout<<"after"<<endl;
    //for(auto e : arr)
    //{
    //    cout<<e<<" ";
    //}
    //cout<<sizeof(long)<<endl;
    INT i = 999;
    cout<<i<<endl;
    return 0;
}
