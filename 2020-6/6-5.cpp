/*************************************************************************
  > File Name: 6-5.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月29日 星期五 17时43分31秒
 ************************************************************************/

#include "Header.hpp"


//天数 巧克力的数量
int n,m;


//计算第一天以mid个巧克力的数量来吃，m天共需要巧克力的数量
int sum(int &mid)
{
	int tmp = mid;
	int total = tmp;
	for (int i = 0; i < n -1; ++i)
	{
    //向上取整
		tmp = (tmp + 1) / 2;
		total += tmp;
	}
	return total;
}

int fun()
{
  //二分法的left和right区间
  int left = 1;
  int right = m;

  //开始二分枚举
  while(left <= right)
  {
    //假设第一天吃掉巧克力的数量为mid
    int mid = (left + right + 1) / 2;

    //获得以mid开始m天公需要巧克力的数量
    int num_count = sum(mid);

    //如果相等，直接返回
    if(num_count == m)
    {
      return mid;
    }
    //如果小于，说明第一天还可以吃多点
    else if(num_count < m)
    {
      left = mid  + 1;
    }
    //如果大于，说明第一天吃多了，需要减少
    else 
    {
      right = mid - 1;
    }
  }
  return right;
}

int main()
{
  cin>>n>>m;
  cout<<fun()<<endl;
  return 0;
}

