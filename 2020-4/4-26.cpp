#include<algorithm>
#include <iostream>
#include<cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;

//分别代表硬币的数量和凑金额的范围m
int n,m;

//数组a，代表每个硬币的面值
int a[maxn];

int main()
{
  cin>>m>>n;
  for(int i = 0;i < n;i++)
  {
    cin>>a[i];
  }

  //排序
  sort(a,a + n);

  //过滤掉面值大于m的硬币
  while(a[n - 1] > m) 
    n--;

  //把范围m当作一种特殊的硬币
  a[n]=m + 1;

  if(a[0] != 1)
  {
    puts("-1");
  }
  else
  {
    //保存已经凑出的金额范围
    int sum=0;

    //保存所需硬币的个数
    int ans=0;

    //开始遍历每个硬币的面额，直到凑出m面值的硬币出来，注意⚠️最后一枚
    //硬币的面值是m + 1，我们只需要凑出m即可，所以不会用到m + 1
    for(int i=0;i<n;i++)
    {
      //根据公式求去所需硬币的个数k，向上取整
      int k = (a[i + 1] - 1 - sum + a[i] - 1) / a[i];

      //更新已经求的的面额范围sum
      sum += k * a[i];

      //跟新结果
      ans += k;
    }
    cout<<ans<<endl;
  }
  return 0;
}

