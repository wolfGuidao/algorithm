#include "Header.hpp"

int dp(vector<int>& coins,int amount)
{
  if(amount == 0)
  {
    return 0;
  }

  if(amount < 0)
  {
    return -1;
  }

  int ret = INT_MAX;
  for(int i = 0;i < coins.size();i++)
  {
    int temp = dp(coins,amount - coins[i]);
    if(temp == -1)
    {
      continue;
    }
    ret = min(ret,1 + temp);
  }

  if(ret == INT_MIN)
  {
    ret = -1;
  }

  return ret;
}

int main()
{
  vector<int> coins = {1,2,5,10};
  int amount = 23;
  cout<<dp(coins,amount)<<endl;
}
