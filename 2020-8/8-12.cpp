/*************************************************************************
# File Name: 8-12.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月29日 星期三 13时40分29秒
*************************************************************************/

#include <iostream>
using namespace std;

//class A 
//{
//    public:
//    virtual void Print(int a = 999)
//    {
//        cout<<a<<endl;
//    }
//};
//
//class B : public A 
//{
//    public:
//    virtual void Print(int a = 666)
//    {
//        cout<<a<<endl;
//    }
//};
//
//void Test(A& a)
//{
//    a.Print();
//}
//
//int main()
//{
//    B b;
//    Test(b);
//    return 0;
//}

void Print(int& a)
{
    cout<<a<<endl;
}

void Print(int* a)
{
    cout<<*a<<endl;
}

//void Print(int a)
//{
//    cout<<a<<endl;
//}

int main()
{
    int a = 999;
    int& ra = a;
    int* pa = &a;
    Print(ra);
    Print(pa);
    return 0;
}

class Solution {
public:
    int massage(vector<int>& nums) {
        //vector<int> dp(nums.size() + 2,0);
        int dp_2 = 0;
        int dp_1 = 0;

        for(int i = nums.size() - 1;i >= 0;i--)
        {
            //dp[i] = max(dp[i + 2] + nums[i],dp[i + 1]);
            int dp_i = max(dp_2 + nums[i],dp_1);
            dp_2 = dp_1;
            dp_1 = dp_i;
        }
        //return dp[0];
        return dp_1;
    }
};

class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2 || n == 3)
        {
            return n - 1;
        }
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        //枚举每一段最优的情况，那么n求出来的结果肯定是有最有结果组成的
        for(int i = 4;i <= n;i++)
        {
            int count = INT_MIN;
            //对于每一小段，求取最大的乘积结果
            for(int j = 1;j <= i / 2;j++)
            {
                //这里虽然看似只有j和i - j两段，但是这两段肯定是最优的结果
                count = max(count,dp[j] * dp[i - j]);
            }
            dp[i] = count;
        }
        return dp[n];
    }
};


/*
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool dp(vector<vector<char>>& board,string& word,int index,int x,int y,vector<vector<bool>>& visted)
    {
        visted[x][y] = true;

        if(index == word.size())
        {
            return true;
        }

        for(auto e : dir)
        {
            int new_x = x + e[0];
            int new_y = y + e[1];
            if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size() || board[new_x][new_y] != word[index] || visted[new_x][new_y])
            {
                continue;
            }
            else 
            {
                if(dp(board,word,index + 1,new_x,new_y,visted))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
        {
            return false;
        }

        if(word.empty())
        {
            return true;
        }

        for(int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[i].size();j++)
            {
                vector<vector<bool>> visted(board.size(),vector<bool>(board[0].size(),false));
                if(board[i][j] == word[0])
                {
                    if(dp(board,word,1,i,j,visted))
                    {
                        return true;
                    }
                }
                
            }
        }
        return false;
    }
};
*/

/*
class Solution {
    //dir 数组定义四个方向, 当前位置的上下左右
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //其中 vis 数组用于标识进入过的格子, idx 表示要找的下一个坐标, 也就是 word 的前 idx 个字母已经找到了
    bool dfs(vector<vector<char>>& board, vector<vector<int>>&vis, int i, int j, string& word, int idx)
    {
        //标识 (i, j) 位置被寻找过了
        vis[i][j] = 1;
        if(idx == word.size()) 
            return true;
        
        idx ++;
        //向四个方向寻找
        for(auto xy : dir)
        {
            int x = i + xy[0], y = j + xy[1];
            
            //如果不满足条件, 换其他方向寻找
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || vis[x][y] || board[x][y] != word[idx - 1]) 
                continue;
            else
            {
                //满足条件, 继续深搜
                if(dfs(board, vis, x, y, word, idx)) 
                    return true;
            }
        }
        //回溯
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                //找寻等于 word[0] 的位置作为搜索的入口
                if(board[i][j] == word[0])
                {
                    if(dfs(board, vis, i, j, word, 1)) 
                        return true;
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if(board.size() == 0) 
            return false;
        for (int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if (dfs(board,word,i,j,0))
                    {
                        return true;
                    }
                }
                
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i,int j,int length)
    {
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || length >= word.size() || word[length] != board[i][j])
        {
            return false;
        }

        if(length == word.size() - 1 && word[length] == board[i][j])
        {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '0';
        bool flag = dfs(board,word,i,j + 1,length + 1)
                  ||dfs(board,word,i,j - 1,length + 1)
                  ||dfs(board,word,i + 1,j,length + 1)
                  ||dfs(board,word,i - 1,j,length + 1);

        board[i][j] = temp;
        return flag;
    }
};

