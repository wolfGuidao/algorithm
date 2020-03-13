#include "Header.hpp"

int lengthOfLIS(vector<int>& nums)
{
  vector<int> dp (nums.size(),1);
  for(size_t i = 0;i < nums.size();i++)
  {
    for(size_t j = 0;j < i;j++)
    {
      if(nums[j] < nums[i])
      {
        dp[i] = max(dp[i],dp[j] + 1);
      }
    }
  }
  sort(dp.begin(),dp.end());
  return dp.back();
}

int main()
{
  vector<int> arr = {10,9,2,5,3,7,101,18};
  cout<<lengthOfLIS(arr)<<endl;
  return 0;
}
