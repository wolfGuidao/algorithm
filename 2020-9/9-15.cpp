/*************************************************************************
# File Name: 9-15.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月17日 星期四 21时19分36秒
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */

	//大堆，存放的是元素较小的
    priority_queue<int,vector<int>,less<int>> small;
    //小堆，存放的是元素较大的
    priority_queue<int,vector<int>,greater<int>> large;

    MedianFinder() {

    }
    
    //谁的元素个数少往谁里面插，注意插入的方式
    void addNum(int num) {
        if (small.size() >= large.size()) 
        {
        	//往large中插入元素需要先插入到small中，然后再插入到large中
            small.push(num);
            large.push(small.top());
            small.pop();
        } 
        else 
        {
        	//往small中插入元素同理
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(large.size() < small.size())
        {
            return small.top();
        }
        else if(large.size() > small.size())
        {
            return large.top();
        }

        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#if 0
int main()
{
    int n,p;
    cin>>n>>p;

    vector<vector<int>> arr;
    for(int i = 0;i < n;i++)
    {
        int count;
        int weight;
        int value;
        vector<int> temp;
        cin>>count>>weight>>value;
        temp.push_back(weight);
        temp.push_back(value);

        while(count--)
        {
            arr.push_back(temp);
        }
    }

    vector<vector<int>> dp(arr.size() + 1,vector<int>(p + 1,0));
    for(int i = 1;i <= arr.size();i++)
    {
        for(int w = 1;w <= p;w++)
        {
            if(arr[i - 1][0] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else 
            {
                dp[i][w] = max(dp[i - 1][w],dp[i - 1][w - arr[i - 1][0]] + arr[i - 1][1]);
            }
        }
    }


    cout<<dp[arr.size()][p]<<endl;
    //int ret = 0;
    //for(auto& e : dp)
    //{
    //    for(auto& m : e)
    //    {
    //        ret = max(ret,m);
    //    }
    //}

    //cout<<ret<<endl;
    return 0;
}
#endif 

int Func(int& x,int y)
{
    return (x++) + y;
}

char* Get_str()
{
    char* arr = "abcd";
    return arr;
}

int main()
{
    char* p = Get_str();
    printf("%s\n",p);
}
