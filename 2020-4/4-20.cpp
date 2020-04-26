/*
 *小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

 输入描述:
 每个输入包含一个测试用例。
 每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
 接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。

 输出描述:
 输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。

 输入例子1:
 5
 2 3 3 3

 输出例子1:
 9
 * */
#include <iostream>
#include <algorithm>
#include<string.h>
#include<map>
#include<iterator>
#include<math.h>
using namespace std;
const int mod =1000000007;
int k;
int a,x,b,y;
int dp[1010][210];
int len[210];
int main()
{
  cin>>k;
  cin>>a>>x>>b>>y;
  int length=x+y;
  memset(dp,0,sizeof(dp));
  memset(len,0,sizeof(len));
  dp[0][0]=1;
  for(int i=1;i<=x;i++)
    len[i]=a;
  for(int i=x+1;i<=length;i++)
    len[i]=b;
  for(int i=0;i<=k;i++)
    for(int j=1;j<=length;j++)
    {
      if(i>=len[j])
      {
        dp[i][j]=(dp[i][j-1]+dp[i-len[j]][j-1])%mod;

      }
      else
      {
        dp[i][j]=dp[i][j-1]%mod;

      }

    }
  cout<<dp[k][length]<<endl;
  return 0;

}
