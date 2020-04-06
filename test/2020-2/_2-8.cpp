#include "Header.hpp"

int _count = 0;
int dp[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>>& arr,int i,int j)
{
  for(int i = 0;i < 4;i++)
  {
    int x = i + dp[i][0];
    int y = j + dp[i][1];
    if(x < arr.size() && x >= 0 && y < arr[0].size() && y >= 0 && arr[i][j] < arr[x][y])
    {
      _count = 1 + dfs(arr,x,y);
    }
  }
  return _count;
}

void longestIncreasingPath(vector<vector<int>>& matrix)
{
  int count_ = 0;
  for(int i = 0;i < matrix.size();i++)
  {
    for(int j = 0;j < matrix[0].size();j++)
    {
      count_ = max(count_,dfs(matrix,i,j));
    }
  }
  cout<<count_<<endl;
}
int main()
{
  vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
  longestIncreasingPath(arr);
  return 0;
}
