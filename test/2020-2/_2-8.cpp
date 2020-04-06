#include "Header.hpp"

int dp[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>>& arr,int i,int j)
{
  int count = 0;
  for(int i = 0;i < 4;i++)
  {
    int x = i + dp[i][0];
    int y = j + dp[i][1];
    if(x < arr.size() && x >= 0 && y < arr[0].size() && y >= 0 && arr[i][j] < arr[x][y])
    {
      count = 
    }
  }
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{

}
int main()
{
  return 0;
}
