#include "Header.hpp"

vector<vector<int>> tag = {{-1,0},{1,0},{0,1},{0,-1}};
vector<vector<int>> falg;
size_t rows;
size_t cols;
int dfs(vector<vector<int>>& arr,size_t x,size_t y)
{
  if(falg[x][y] != 0)
  {
    return falg[x][y];
  }
  int count = 0;
  for(size_t i = 0;i < 4;i++)
  {
    int xx = x + tag[i][0];
    int yy = y + tag[i][1];
    if(x >=0 && x < rows && y >= 0 && y < cols && arr[xx][yy] > arr[x][y])
    {
      count = max(count,dfs(arr,xx,yy));
    }
  }
  falg[x][y] = count + 1;
  return falg[x][y];
}

class Solution {
  public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int> > memo;
    int dfs(vector<vector<int> >& matrix, int r, int c, int R, int C)
    {
      if (memo[r][c] != 0) 
      {
        return memo[r][c];

      }
      int t = 0;
      for (int i = 0; i < 4; ++i)
      {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
          t = max(t, dfs(matrix, nr, nc, R, C));

        }

      }
      memo[r][c] = 1 + t;
      return memo[r][c];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      if (matrix.empty() || matrix[0].empty()) 
        return 0;
      int R = matrix.size();
      int C = matrix[0].size();
      memo = vector<vector<int> >(R, vector<int>(C, 0));
      int res = 0;
      for (int i = 0; i < R; ++i)
      {
        for (int j = 0; j < C; ++j) 
        {
          res = max(res, dfs(matrix, i, j, R, C));
        }
      }
      return res;
    }
};

int main()
{
  //int count = 0;
  vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
  //rows = arr.size();
  //cols = arr[0].size();
  //falg = vector<vector<int>> (rows,vector<int>(arr[0].size(),0));
  //for(size_t i = 0;i < rows;i++)
  //{
  //  for(size_t j = 0;j <arr[i].size();i++)
  //  {
  //    count = max(count,dfs(arr,i,j));
  //  }
  //}
  //cout<<count<<endl;
  Solution so;
  cout<<so.longestIncreasingPath(arr)<<endl;;
  return 0;
}
