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
