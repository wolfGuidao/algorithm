#include "Header.hpp"

vector<int> GetNextBig(vector<int>& arr)
{
  stack<int> s;
  vector<int> dp(arr.size());

  for(int i = arr.size() - 1;i >= 0;i--)
  {
    while(!s.empty() && s.top() <= arr[i])
    {
      s.pop();
    }
    dp[i] = s.empty() ? -1 : s.top();
    s.push(arr[i]);
  }
  return dp;
}

int main()
{
  vector<int> arr = {2,1,2,4,3};
  vector<int> dp = GetNextBig(arr);
  for(auto e : dp)
  {
    cout<<e<<"-";
  }
  cout<<endl;
  return 0;
}
