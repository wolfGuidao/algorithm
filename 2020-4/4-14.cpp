/*
 *作为程序员的小Q，他的数列和其他人的不太一样，他有个数。
 老板问了小Q一共 m次，每次给出一个整数, 要求小Q把这些数每分为一组，然后把每组进行翻转，小Q想知道每次操作后整个序列中的逆序对个数是多少呢？

 例如:
 对于序列1 3 4 2，逆序对有(4, 2),(3, 2),总数量为2。
 翻转之后为2 4 3 1，逆序对有(2, 1),(4, 3), (4, 1), (3, 1),总数量为4。

 输入描述:
 第一行一个数
 第二行个数，表示初始的序列()
 第三行一个数
 第四行m个数表示

 输出描述:
 m行每行一个数表示答案。

 输入例子1:
 2
 2 1 4 3
 4
 1 2 0 2

 输出例子1:
 0
 6
 6
 0

 例子说明1:
 初始序列2 1 4 3
 2^{q_1} = 2 ->
 第一次：1 2 3 4 -> 逆序对数为0
 2^{q_2} = 4 ->
 第二次：4 3 2 1 -> 逆序对数为6
 2^{q_3} = 1 ->
 第三次：4 3 2 1 -> 逆序对数为6
 2^{q_4} = 4 ->
 第四次：1 2 3 4 -> 逆序对数为0
 * */

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
