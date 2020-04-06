#include "Header.hpp"

//找零钱问题

int dp(vector<int>& coins,int amount)
{
  //递归出口
  if(amount == 0)
  {
    return 0;
  }

  if(amount < 0)
  {
    return -1;
  }

  //记录所需金币的最小数量
  int count = INT_MAX;
  for(auto e : coins)
  {
    //记录在选取金额为e的硬币后共需要的硬币个数
    int temp = dp(coins,amount - e);

    //如果temp等于-1，说明上次选取金额为e后，目标金额变为负数，说明选取e这个硬币不合适
    //直接循环判断下一个硬币
    if(temp == -1)
    {
      continue;
    }

    //反之就是选取金额e后的目标金额大于等于0，
    count = min(count,temp + 1);
  }

  if(count == INT_MAX)
  {
    return -1;
  }

  return count;
}

int main()
{
  //vector<int> arr = {1,2,5};
  vector<int> arr = {2};
  cout<<dp(arr,3)<<endl;
  return 0;
}
