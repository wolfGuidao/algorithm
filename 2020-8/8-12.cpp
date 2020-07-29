/*************************************************************************
# File Name: 8-12.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月29日 星期三 13时40分29秒
*************************************************************************/

#include <iostream>
using namespace std;

//class A 
//{
//    public:
//    virtual void Print(int a = 999)
//    {
//        cout<<a<<endl;
//    }
//};
//
//class B : public A 
//{
//    public:
//    virtual void Print(int a = 666)
//    {
//        cout<<a<<endl;
//    }
//};
//
//void Test(A& a)
//{
//    a.Print();
//}
//
//int main()
//{
//    B b;
//    Test(b);
//    return 0;
//}

void Print(int& a)
{
    cout<<a<<endl;
}

void Print(int* a)
{
    cout<<*a<<endl;
}

//void Print(int a)
//{
//    cout<<a<<endl;
//}

int main()
{
    int a = 999;
    int& ra = a;
    int* pa = &a;
    Print(ra);
    Print(pa);
    return 0;
}

class Solution {
public:
    int massage(vector<int>& nums) {
        //vector<int> dp(nums.size() + 2,0);
        int dp_2 = 0;
        int dp_1 = 0;

        for(int i = nums.size() - 1;i >= 0;i--)
        {
            //dp[i] = max(dp[i + 2] + nums[i],dp[i + 1]);
            int dp_i = max(dp_2 + nums[i],dp_1);
            dp_2 = dp_1;
            dp_1 = dp_i;
        }
        //return dp[0];
        return dp_1;
    }
};

class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2 || n == 3)
        {
            return n - 1;
        }
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        //枚举每一段最优的情况，那么n求出来的结果肯定是有最有结果组成的
        for(int i = 4;i <= n;i++)
        {
            int count = INT_MIN;
            //对于每一小段，求取最大的乘积结果
            for(int j = 1;j <= i / 2;j++)
            {
                //这里虽然看似只有j和i - j两段，但是这两段肯定是最优的结果
                count = max(count,dp[j] * dp[i - j]);
            }
            dp[i] = count;
        }
        return dp[n];
    }
};

