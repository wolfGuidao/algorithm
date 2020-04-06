#include "Header.hpp"

//542. 01 矩阵
//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
//
//两个相邻元素间的距离为 1 。
//
//示例 1:
//输入:
//
//0 0 0
//0 1 0
//0 0 0
//输出:
//
//0 0 0
//0 1 0
//0 0 0
//示例 2:
//输入:
//
//0 0 0
//0 1 0
//1 1 1
//输出:
//
//0 0 0
//0 1 0
//1 2 1
//注意:
//
//给定矩阵的元素个数不超过 10000。
//给定矩阵中至少有一个元素是 0。
//矩阵中的元素只在四个方向上相邻: 上、下、左、右。

//方法一：暴力递归

vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
  int rows = matrix.size();
  if (rows == 0)
    return matrix;

  int cols = matrix[0].size();

  vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));

  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      if (matrix[i][j] == 0)
        dist[i][j] = 0;
      else 
      {
        for (int k = 0; k < rows; k++)
          for (int l = 0; l < cols; l++)
            if (matrix[k][l] == 0) 
            {
              dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
            }
      }
    }
  }
  return dist;
}

//方法二：动规
class Solution 
{
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
      int rows = matrix.size();
      if (rows == 0)
        return matrix;
      int cols = matrix[0].size();

      //dp数组，用来保存每个位置距离0值的距离
      vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX - 100000));

      //从左上往右下更新
      for (int i = 0; i < rows; i++) 
      {
        for (int j = 0; j < cols; j++) 
        {
          if (matrix[i][j] == 0)
            dp[i][j] = 0;
          else 
          {
            if (i > 0)
              dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);

            if (j > 0)
              dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
          }
        }
      }

      //从右下往左上更新
      for (int i = rows - 1; i >= 0; i--) 
      {
        for (int j = cols - 1; j >= 0; j--) 
        {
          if (i < rows - 1)
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);

          if (j < cols - 1)
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
        }
      }
      return dp;
    }
};
