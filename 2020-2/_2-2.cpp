#include "Header.hpp"

int main()
{
  string arr = "bbbcb";
  vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),1));
  
  for(int i = arr.size() - 1;i >= 0;i--)
  {
    for(int j = i + 1;j < arr.size();j++)
    {
      if(arr[i] == arr[j])
      {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      }
      else 
      {
        dp[i][j] = max(dp[i][j - 1],dp[i + 1][j]);
      }
    }
  }
  cout<<dp[0][arr.size() - 1]<<endl;
  return 0;
}
