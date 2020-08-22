/*************************************************************************
# File Name: 8-20.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月22日 星期六 22时22分11秒
*************************************************************************/
class Solution {
public:
    //x-1,y-1   x-1,y   x-1,y+1
    //x,y-1     x,y     x,y+1
    //x+1,y-1   x+1,y   x+1,y+1

    int GetActivate(vector<vector<int>>& board,int x,int y)
    {
        int m = board.size();
        int n = board[0].size();
        int ret = 0;
        if(x - 1 >= 0 && board[x - 1][y])
        {
            ret++;
        }
        
        if(x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1])
        {
            ret++;
        }
        
        if(y - 1 >= 0 && board[x][y - 1])
        {
            ret++;
        }
        
        if(x + 1 < m && y - 1 >= 0 && board[x + 1][y - 1])
        {
            ret++;
        }
        
        if(x + 1 < m && board[x + 1][y])
        {
            ret++;
        }
       
        if(x + 1 < m && y + 1 < n && board[x + 1][y + 1])
        {
            ret++;
        }
        
        if(y + 1 < n && board[x][y + 1])
        {
            ret++;
        }
        
        if(x - 1 >= 0 && y + 1 < n && board[x - 1][y + 1])
        {
            ret++;
        }

        return ret;
    }

    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
        {
            return ;
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> arr(m,vector<int>(n));
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int count = GetActivate(board,i,j);
                if(board[i][j] == 1)
                {   
                    if(count < 2 || count > 3)
                    {
                        arr[i][j] = 0;
                    }
                    else if(count == 2 || count == 3)
                    {
                        arr[i][j] = 1;
                    }
                }
                else if(board[i][j] == 0)
                {
                    if(count == 3)
                    {
                        arr[i][j] = 1;
                    }
                    else 
                    {
                        arr[i][j] = 0;
                    }
                }
            }
        }

        board = arr;
    }
};



class Solution {
public:

    int GetMin(vector<int>& arr,int target,vector<int>& visted)
    {
        if(target < 0)
        {
            return -1;
        }

        if(visted[target] != -1)
        {
            return visted[target];
        }

        if(0 == target)
        {
            return 0;
        }

        int ret = INT_MAX;
        for(auto e : arr)
        {
            int val = GetMin(arr,target - e,visted);
            if(val == -1)
            {
                continue;
            }

            ret = min(ret,val + 1);
        }

        visted[target] = ret;
        return ret;
    }

    int numSquares(int n) {
        if(n < 1)
        {
            return 0;
        }

        vector<int> arr;
        for(int i = 1;i <= n;i++)
        {
            if(i * i <= n)
            {
                arr.push_back(i * i);
            }
            else 
            {
                break;
            }
        }

        /*
        vector<vector<int>> dp(arr.size() + 1,vector<int>(n + 1,0));
        for(int i = 0;i < n + 1;i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1;i <= arr.size();i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(j < arr[i - 1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i][j - arr[i - 1]] + 1,dp[i-1][j]);
            }
        }
        return dp[arr.size()][n];
        */

        vector<int> visted(n + 1,-1);
        return GetMin(arr,n,visted);
    }
};


/*
class Solution {
public:
    int numSquares(int n) {
        if(n==0)
            return 0;
        int ceil = sqrt(n);
        vector<vector<int> > dp(ceil+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)
            dp[0][i] = i;
        for(int i=0;i<=ceil;i++)
            dp[i][0] = 0;

        for(int i=1;i<=ceil;i++){
            for(int j=1;j<=n;j++){
                if(j < i*i)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i][j-i*i]+1,dp[i-1][j]);
            }
        }
        return dp[ceil][n];
    }
};
*/
