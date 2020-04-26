/*
 *
 *小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。

输出描述:
输出一个数表示小Q第一天最多能吃多少块巧克力。

输入例子1:
3 7

输出例子1:
4
 * */


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
