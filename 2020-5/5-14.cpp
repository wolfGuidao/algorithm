#include "Header.hpp"

//控制4个方向遍历
vector<vector<int>> dict = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<int>> arr,int i, int j)
{
  //记录结果
  int ret = 0;
  for(auto e : dict)
  {
    //当前往上下左右4个方向在的任意一个坐标
    int x = i + e[0];
    int y = j + e[1];

    //判断当前坐标是否合法，并且是否满足递增的条件
    if(x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[x][y] > arr[i][j])
    {
      //满足就继续以的当前节点第归往下判断
      ret = max(ret,dfs(arr,x,y));
    }
  }
  //更新结果
  return ++ret;
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
  if (matrix.size() == 0) 
    return 0;
  int m = matrix.size();
  int n = matrix[0].size();
  int ans = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      ans = max(ans, dfs(matrix, i, j));
  return ans;
}

int main()
{
  vector<vector<int>> arr = {{9,9,4}, {6,6,8},{2,1,1}};
  cout<<longestIncreasingPath(arr)<<endl;;
  return 0;
}
