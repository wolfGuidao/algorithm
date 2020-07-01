/*************************************************************************
    > File Name: 7-14.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月01日 星期三 19时38分47秒
 ************************************************************************/

#include "Header.hpp"

#include<iostream>
using namespace std;
 
//n代表天数，m代表巧克力的数量
int n, m;

//函数用来求第一天吃mid块巧克力，根据题意N天共吃掉巧克力的数量
int sum(int &mid)
{
	int tmp = mid;
	int total = tmp;
	for (int i = 0; i < n -1; ++i)
	{
		tmp = (tmp + 1) / 2;
		total += tmp;
	}
	return total;
}

int fun()
{
	int l = 1;
	int r = m;
	while (l <= r)
	{
		int mid = (l + r + 1) / 2;
		int bool_int = sum(mid);
		if (bool_int == m)
		{
			return mid;
		}
		else if (bool_int < m)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return r;
 
}
int main()
{
	cin >> n >> m;
	cout << fun() << endl;
	return 0;
}
