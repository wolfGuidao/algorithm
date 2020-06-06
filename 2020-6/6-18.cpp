/*************************************************************************
    > File Name: 6-18.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月05日 星期五 22时32分46秒
 ************************************************************************/

#include "Header.hpp"

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>ret;
		int m = matrix.size();
		int n = matrix[0].size();
		int num = m * n;
		int x = 0;
		int y = 0;
		//ret.push_back(matrix[0][0]);
		while (num  > 0)
		{
			while (y + 1 < n&&matrix[x][y + 1] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				y++;
				num--;
			}
			while (x + 1 < m&&matrix[x + 1][y] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				x++;
				num--;
			}
			while (y - 1 >= 0 && matrix[x][y - 1] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				y--;
				num--;
			}
			while (x - 1 >= 0 && matrix[x - 1][y] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				x--;
				num--;
			}
			if (num == 1)
			{
				ret.push_back(matrix[x][y]);
				num--;
			}
		}
		return ret;
	}
};

int main()
{
  vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  
  int count = 9;
  
  while(count)
  {

  }
  return 0;
}
