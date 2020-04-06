#include "Header.hpp"

//A的个数


int Max(int a,int b,int c)
{
  return max(a,max(b,c));
}
#if 0
//N:代表当前剩余的操作次数
//A_num:代表当前屏幕上的A的数量
//A_copy：代表当前剪切板当中A的数量
int dp(int N,int A_num,int A_copy)
{

  //如果当前没有操作次数了，就直接返回屏幕当中A的数量
  if(N <=  0)
  {
    return A_num;
  }

  //反之如果还有操作次数：返回直接按A、按C-A，C_C、按C-V所得A的的最大结果
  return Max(dp(N - 1,A_num + 1,A_copy),dp(N - 2,A_num,A_num),dp(N - 1,A_num + A_copy,A_copy));
}


void Amax(int N)
{
  if(N == 0)
  {
    return ;
  }

  cout<<dp(N,0,0)<<endl;;
}
#endif

int maxA(int N)
{
  if(N == 0)
  {
    return 0;
  }

  //dp[i]:代表操作数为i时最大的A的数量
  vector<int> dp(N + 1,0);

  for(int i = 1;i <= N;i++)
  {
    //这种情况代表直接按A，本次的Adam个是在上一次A的个数上 + 1 
    dp[i] = dp[i - 1] + 1;

    //这个循环是定位开始按C-V的位置，每次至少从2开始是为了给C-A,C-C预留2次操作数
    for(int j = 2;j < i;j++)
    {
      //那么本次A的最大数量就是C-V的次数 * 剪切板当中A的数量和直接按A的数量进行比较
      dp[i] = max(dp[i],dp[j - 2] * (i - j + 1));
    }
  }
  return dp[N];
}

int main()
{
  cout<<maxA(3)<<endl;
  return 0;
}
