#include "Header.hpp"

int GetA(int N)
{
  vector<int> dp(N,0);

  for(int i = 1;i <= N;i++)
  {
    //执行按A，数量就直接+1
    dp[i] = dp[i - 1] + 1;
    for(int j = 2;j < i;j++)
    {
      //执行C-A C-C ，要执行他们就必须为其预留次数
      //最后A的数量就等于前两次按下C-A C-C，再按i - j + 1 次C-V
      //我们不知道j从哪里开始合适就只能及逆行枚举
      dp[i] = max(dp[i],dp[j - 2] * (i - j + 1));
    }
  }
  return dp[N];
}

int main()
{
  int N = 7;
  cout<<GetA(N)<<endl;
  return 0;
}
