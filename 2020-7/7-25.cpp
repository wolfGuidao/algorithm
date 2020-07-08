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

class Solution {
public:
    // 时间复杂度 O(N)
bool canFinish(vector<int> piles, int speed, int H) 
{
    int time = 0;
    for (int n : piles) 
    {
        time += timeOf(n, speed);
    }
    return time <= H;
}

int timeOf(int n, int speed) 
{
    return (n / speed) + ((n % speed > 0) ? 1 : 0);
}

int getMax(vector<int> piles) 
{
    int maxx = 0;
    for (int n : piles)
        maxx = std::max(n, maxx);
    return maxx;
}

    int minEatingSpeed(vector<int>& piles, int H) {
        // 套用搜索左侧边界的算法框架
    int left = 1, right = getMax(piles) + 1;
    while (left < right) 
    {
        // 防止溢出
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, H)) 
        {
            right = mid;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    return left;
    }
};

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

