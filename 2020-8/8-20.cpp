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
