/*************************************************************************
    > File Name: 7-24.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月06日 星期一 19时39分22秒
 ************************************************************************/

#include "Header.hpp"

#include <iostream> 
#include <vector>
using namespace std;
 
//该函数用来计算n个位置里面选2个的所有情况
long long C_N_2(long long n)
{
    return (n-1) * n / 2;
}
 
int main()
{
	//要用long long类型，否则会越界
    long long n, d, count = 0;
    cin>> n>> d;
    
    //存储N个建筑的位置
    vector<long long> v(n);
    //输入／遍历判断
    
    int j = 0;//标记满足题意的距离D的最左边下表
    for (int i = 0; i < n; i++) 
    {
        cin>> v[i];

		//如果当前下标大于等于2（i >= 2），从0开始的，因为至少有3个位置嘛
		//如果v[i] - v[j]) > d代表当前位置到j的距离超过D，不满足情况
		//需要增大最左下标j
        while (i >= 2 && (v[i] - v[j]) > d) 
        {
            j++;
        }
	
		//走到这里代表j位置到当前位置i的距离是刚好小于等于D的（满足最大的情况）
		//结果就是从i - j中间的位置中选2个位置
        count += C_N_2(i - j);
    }
    cout << count % 99997867; 
    return 0;
}
