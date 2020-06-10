/*************************************************************************
    > File Name: 6-22.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月10日 星期三 17时29分15秒
 ************************************************************************/

#include "Header.hpp"

#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

/****************************
func:获取n个骰子指定点数和出现的次数
para:n:骰子个数;sum:指定的点数和
return:点数和为sum的排列数
*****************************/
int getNSumCount(int n, int sum)
{
	if(n<1||sum<n||sum>6*n)
	{
		return 0;
	}
	if(n==1)
	{
		return  1;
	}
	int resCount=0;
	resCount=getNSumCount(n-1,sum-1)+getNSumCount(n-1,sum-2)+
			 getNSumCount(n-1,sum-3)+getNSumCount(n-1,sum-4)+
			 getNSumCount(n-1,sum-5)+getNSumCount(n-1,sum-6);
	return resCount;
}

//验证
int main()
{
	int n = 0;
	while(true)
	{
		cout<<"input dice num：";
		cin>>n;
		for(int i=n;i<=6*n;++i)
		{
			cout<<"f("<<n<<","<<i<<")="<<getNSumCount(n,i)<<endl;
		}
	}
}


