/*************************************************************************
    > File Name: 7-12.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月30日 星期二 19时51分24秒
 ************************************************************************/

#include "Header.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
 
long long  Merge(vector<int> info,int begin,int end,vector<int> temp)
{
    if(begin == end)
    {
        return 0;
    }
    long long count = 0;
     
    int mid = (begin + end) >> 1;
    long long left = Merge(info,begin,mid,temp);
    long long right = Merge(info,mid + 1,end,temp);
     
    int begin1 = begin;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = end;
    int index = end;
     
    while(begin1 <= end1 && begin2 <= end2)
    {
        if(info[end1] > info[end2])
        {
            count = count + end2 - begin2 + 1;
            temp[index--] = info[end1--];
        }
        else
        {
            temp[index--] = info[end2--];
        }
    }
    while(end1 >= begin1)
    {
        temp[index--] = info[end1--];
    }
    while(end2 >= begin2)
    {
        temp[index--] = info[end2--];
    }
    //拷贝
    for(int i =  begin;i <= end ;i++)
    {
        info[i] = temp[i];
    }
         
        //左边区间的逆序对的个数 + 由边区间的逆序对的个数 + 合并两个区间的逆序对的个数
    return (left + right + count);
}
 
void InversePairs(vector<int> info)
{
    vector<int> temp(info.size());
     
    cout<<Merge(info,0,info.size() - 1,temp)<<endl;
}
 
void Reverse(vector<int>& info,int num)
{
    int count = info.size() / num;
    for(int i = 0;i < count;i++)
    {
        reverse((info.begin() + i * num),info.begin() + ((i + 1) * num));
         
    }
    InversePairs(info);
}
 
void GetReverseCount(vector<int>& info,vector<int>& ans)
{
    for(auto e : ans)
    {
        int num = pow(2,e);
        Reverse(info,num);
    }
}
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(pow(2,n));
    for(int i = 0;i < pow(2,n);i++)
    {
        cin>>v[i];
    }
    int num;
    cin>>num;
    vector<int> ans(num);
    for(int i = 0;i < num;i++)
    {
        cin>>ans[i];
    }
    GetReverseCount(v,ans);
     
    return 0;
}

