#include "Header.hpp"

//鸡蛋掉落问题
//N:为楼层
//K:为鸡蛋个数
int dp(int N,int K)
{

  //如果鸡蛋只剩下一个就只能依次遍历剩下的楼层
  if(K == 1)
  {
    return N;
  }

  //如果楼层为0，就直接返回0，不用测试
  if(N == 0)
  {
    return 0;
  }

  int ret = INT_MAX;

  //循环测试在第i层扔鸡蛋，选取最小的结果
  for(int i = 1;i <= N;i++)
  {
    //每次选取在第i层碎或者没碎的最坏情况
    //在第i层碎，就只需要在i层以下的楼层测试，所以共有i - 1层
    //在第i层没碎，就只需要在第i层以上进行测试，所以共有N - i层
    ret = min(ret,max(dp(i - 1,N - 1) + 1,dp(N - i,N) + 1));
  }

  return ret;
}

int main()
{
  cout<<dp(14,3)<<endl;
  return 0;
}
