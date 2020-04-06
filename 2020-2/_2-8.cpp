#include "Header.hpp"

//矩阵中的最长递增路径
//方法一：深度优先遍历
#if 1
//该数组用来控制4个方向
vector<vector<int>> dp = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>>& arr,int i,int j)
{
  //用来计数，注意每个栈帧内初始化时都是0
  int _count = 0;

  //枚举4个方向
  for(auto e : dp)
  {
    int x = i + e[0];
    int y = j + e[1];

    //如果满足情况，就进行递归下去
    if(x < arr.size() && x >= 0 && y < arr[0].size() && y >= 0 && arr[i][j] < arr[x][y])
    {
      //每次求取所有路径中最长的
      //假设：已经连续走了a,b,c,d这4步，但是此时在进行递归时4个方向都不满足情况，那么该程序就会跳出本次递归
      //并把count++返回给上个栈帧，即d的count为1；
      //再假设d的其他方向满足情况，就会继续递归，假设这个方向返回给d栈帧的count为4；
      //那么在返回给c栈帧之前会求个最大值，所以count为2；
      //以此类推，逐层返回
      _count = max(_count,dfs(arr,x,y));
    }
  }
  
  //函数是在返回是++的
  return ++_count;
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

//int main()
//{ 
//  vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
//  longestIncreasingPath(arr);
//  return 0;
//}


#endif

#if 0
class Solution {
  public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    int dfs(vector<vector<int>>& matrix, int i, int j) 
    {
      int ans = 0;
      for ( auto d : dirs ) 
      {
        int x = i + d[0], y = j + d[1];
        if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
          ans = max(ans, dfs(matrix, x, y));

      }
      return ++ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) 
        return 0;
      m = matrix.size();
      n = matrix[0].size();
      int ans = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          ans = max(ans, dfs(matrix, i, j));
      return ans;
    }
};
int main()
{
  vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
  Solution s;
  cout<<s.longestIncreasingPath(arr)<<endl;
  return 0;
}
#endif

//方法二：加个备忘录
vector<vector<int>> dp1 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<int>> demo;
int dfs1(vector<vector<int>>& arr,int i,int j)
{
  int num = 0;
  if(demo[i][j] != -1)
  {
    return demo[i][j];
  }
  for(auto e : dp)
  {
    int x = i + e[0];
    int y = j + e[1];

    if(x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[i][j] < arr[x][y])
    {
      num = max(num,dfs(arr,x,y) + 1);
    }
  }

  demo[i][j] = num ;
  return demo[i][j];
}
//
//int main()
//{
//  int num = 0 ;
//  vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
//  demo = vector<vector<int>>(arr.size(),vector<int>(arr[0].size(),-1));
//  for(int i = 0;i < arr.size();i++)
//  {
//    for(int j = 0;j < arr[0].size();j++)
//    {
//      num = max(num,dfs(arr,i,j));
//    }
//  }
//  cout<<num<<endl;
//  return 0;
//}
