/*************************************************************************
# File Name: 9-21.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月27日 星期日 18时47分02秒
*************************************************************************/
#include <iostream>
using namespace std;

#if 0
static int a = 999;

int main()
{
    cout<<"&a-> "<<&a<<endl;
    static int a = 666;
    cout<<a<<endl;
    cout<<"&a-> "<<&a<<endl;
    return 0;
}
#endif 

class Test;

Test* ss;

class Test 
{
    public:
        static void Print(Test* a)
        {
            cout<<"i am Print()"<<endl;
            cout<<"i am static : "<<test_static<<endl;
            cout<<"i am no static : "<<a->test_no_static<<endl;
            cout<<"i am no static : "<<ss->test_no_static<<endl;
        }
    private:
        static int test_static;
        int test_no_static = 666;
};

int Test::test_static = 999;

#include <vector>
#include <algorithm>

#if 0
bool Cmp(int a,int b)
{
    return a < b;
}
#endif 

#include <thread>

class Cmp 
{
    public:
        bool operator()(int a,int b)
        {
            return a < b;
        }
};

#include <atomic>

int val = 999;
int main()
{
    vector<int> arr {10,9,8,7,6,5,4,3,2,1};
    //sort(arr.begin(),arr.end(),Cmp);
    //sort(arr.begin(),arr.end(),Cmp());//仿函数需要带括号
    sort(arr.begin(),arr.end(),[](int a,int b)
            {
                return a < b;
            });
    for(auto& e : arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    thread t1([](int a){
               a = 666; 
            },std::ref(val));

    t1.join();
    cout<<val<<endl;
    
    atomic<int> test_int {999};
    cout<<test_int<<endl;

    return 0;
}
