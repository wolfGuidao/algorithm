/*************************************************************************
# File Name: 8-4.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月17日 星期五 11时55分08秒
*************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution 
{
    public:
        void Insert(int val)
        {
            if(Left_Max.empty() || val <= Left_Max.top())
            {
                Left_Max.push(val);
            }
            else 
            {
                Right_Min.push(val);
            }

            if(Left_Max.size() == Right_Min.size() + 2)
            {
                Right_Min.push(Left_Max.top());
                Left_Max.pop();
            }

            if(Left_Max.size() + 1 == Right_Min.size())
            {
                Left_Max.push(Right_Min.top());
                Right_Min.pop();
            }
        }

        double Median()
        {
            return Left_Max.size() == Right_Min.size() ? (Left_Max.top() + Right_Min.size()) / 2.0 : Left_Max.top();
        }

    private:
        priority_queue<int,vector<int>,less<int>> Left_Max;
        priority_queue<int,vector<int>,greater<int>> Right_Min;
};


int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    Solution so;

    for(auto e : arr)
    {
        so.Insert(e);
    }

    cout<<so.Median()<<endl;
    return 0;
}

/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        {
            return 0;
        }

        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i = 0;i < matrix.size();i++)
        {
            for(int j = 0;j < matrix[0].size();j++)
            {
                if(j == 0)
                {
                    if(matrix[i][0] == '0')
                        dp[i][j] = 0;
                    else 
                        dp[i][j] = 1;
                }
                else if(matrix[i][j] == '1')
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                else 
                {
                    dp[i][j] = 0;
                }
            }
        }

        int ret = INT_MIN;
        for(int i = 0;i < matrix.size();i++)
        {
            for(int j = 0;j < matrix[0].size();j++)
            {
                int col = 0;
                int row = INT_MAX;
                
                for(int k = i;k >= 0;k--)
                {
                    if(dp[k][j] == 0)
                    {
                        row = INT_MAX;
                        col = 0;
                        continue;
                    }
                    row = min(dp[k][j],row);
                    col++;
                    ret = max(ret,row * col);
                }

                ret = max(ret,row * col);
            }
        }

        return ret;
    }
};
*/

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		int m = 0;
		if (n > 0) { m = matrix[0].size(); }
		vector<vector<int>> heights(n + 1,vector<int>(m + 1,0));
		vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (matrix[i-1][j-1] == '0') { continue; }
				heights[i][j] = heights[i-1][j] + 1;
				for (int k = 1; k <= heights[i][j]; k++) {
					dp[i][j][k] = dp[i][j-1][k] + k;
					ans = max(ans, dp[i][j][k]);
				}
			}
		}
		return ans;
	}
};
