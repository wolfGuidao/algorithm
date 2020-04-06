#include "Header.hpp"

int GetLength(vector<int>& arr)
{
  int ret = 0;
  vector<int> dp(arr.size(),1);
  for(size_t i = 0;i < dp.size();i++)
  {
    for(size_t j = 0;j < i;j++)
    {
      if(arr[i] > arr[j])
        dp[i] = max(dp[i],dp[j] + 1);
    }
  }
  for(auto e : dp)
  {
    ret = max(ret,e);
  }
  return ret;
}

int main()
{
  vector<int> arr = {1,4,2,3,6,5,7,9,8};
  cout<<GetLength(arr)<<endl;
  return 0;
}
