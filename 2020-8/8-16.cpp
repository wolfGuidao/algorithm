/*************************************************************************
# File Name: 8-16.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月09日 星期日 20时41分50秒
*************************************************************************/
#include <iostream>
using namespace std;
#include <set>

class Solution {
public:
    bool IsTrue(vector<pair<int,int>> cur,int row,int col)
    {
        for(auto e : cur)
        {
            if(e.second == col || e.first + e.second == row + col || e.first - e.second == row - col)
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> Trans(vector<vector<pair<int,int>>>& arr,int n)
    {
        vector<vector<string>> ret;

        for(auto e : arr)
        {
            vector<string> temp(n,string(n,'.'));
            for(auto m : e)
            {
                temp[m.first][m.second] = 'Q';
            }
            ret.push_back(temp);
        }
        return ret;
    }

    void dfs(vector<vector<pair<int,int>>>& ret,vector<pair<int,int>>& cur,int curRow,int n)
    {
        if(curRow == n)
        {
            ret.push_back(cur);
            return ;
        }

        for(int i = 0;i < n;i++)
        {
            if(IsTrue(cur,curRow,i))
            {
                cur.push_back({curRow,i});
                dfs(ret,cur,curRow + 1,n);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int,int>>> ret;
        vector<pair<int,int>> cur;
        dfs(ret,cur,0,n);

        return Trans(ret,n);
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
        {
            return {};
        }

        vector<vector<int>> ret;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> temp;
            int Size = que.size();
            for(int i = 0;i < Size;i++)
            {
                Node* node = que.front();
                que.pop();

                temp.push_back(node->val);

                for(auto e : node->children)
                {
                    if(e)
                        que.push(e);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        queue<pair<int,int>> que;

        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    que.push({i,j});
                }
            }
        }

        vector<vector<int>> dir {{1,0},{-1,0},{0,1},{0,-1}};

        int count = 0;
        while(!que.empty())
        {
            int Size = que.size();

            bool flag = false;

            for(int i = 0;i < Size;i++)
            {
                pair<int,int> index = que.front();
                que.pop();

                for(auto e : dir)
                {
                    int new_x = e[0] + index.first;
                    int new_y = e[1] + index.second;

                    if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size())
                    {
                        continue;
                    }

                    if(grid[new_x][new_y] == 1)
                    {
                        flag = true;
                        grid[new_x][new_y] = 2;
                        que.push({new_x,new_y});
                    }
                }
            }
            if(flag)
                count++;
        }

        for(auto e : grid)
        {
            for(auto m : e)
            {
                if(m == 1)
                {
                    return -1;
                }
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1,0);

        //base case:
        dp[0] = 1;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 1; j <= amount; j++)
            {
                if (j - coins[i] >= 0)
                    dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

class Solution {
public:
    bool IsTrue(int num)
    {
        for(int i = 2;i <= sqrt(num);i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int countPrimes(int n) {
        if(n < 2)
        {
            return 0;
        }      

        /*
        int ret = 0;
        for(int i = 2;i < n;i++)
        {
            if(IsTrue(i))
            {
                ret++;
            }
        }

        return ret;
        */

        int count = 0;
        //初始默认所有数为质数
        vector<bool> signs(n, true);
        for (int i = 2; i < n; i++) 
        {
            if (signs[i]) 
            {
                count++;
                for (int j = i + i; j < n; j += i) 
                {
                    //排除不是质数的数
                    signs[j] = false;
                }
            }
        }
    return count;
    }
};

class Solution {
public:
    //void backtrack(vector<vector<int>>& ret,vector<int>& candidates, int& target,vector<int>& track,int index,int cursum)

    vector<vector<int>> ret;
    void backtrack(vector<int>& candidates, int target,vector<int>& track,int index)
    {
        if(0 == target)
        {    
            ret.push_back(track);
            return;
        }

        for(int i = index;i < candidates.size() && target - candidates[i] >= 0;i++)
        {
            if(i > index && candidates[i - 1] == candidates[i])
                continue;

            track.push_back(candidates[i]);
            backtrack(candidates,target - candidates[i],track,i + 1);
            track.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
        {
            return {};
        }

        sort(candidates.begin(),candidates.end());

        vector<int> track;
        
        backtrack(candidates,target,track,0);
        return ret;
    }
};


struct Node 
{
    Node(bool isChar)
    :_isChar(isChar)
    {
        _child.resize(26);
        for(int i = 0;i < 26;i++)
        {
            _child[i] = nullptr;
        }
    }

    bool _isChar;
    vector<Node*> _child;
};

class Trie {
public:
    Node* _root;

    /** Initialize your data structure here. */
    Trie() 
    :_root(new Node(false))
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty())
        {
            return ;
        }

        int index = 0;
        Node* cur = _root;
        while(index < word.size())
        {
            int index_child = word[index] - 'a';
            if(cur->_child[index_child] == nullptr)
            {
                cur->_child[index_child] = new Node(false);
            }
            cur = cur->_child[index_child];
            index++;
        }
        cur->_isChar = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.empty())
        {
            return true;
        }

        Node* cur = _root;
        int index = 0;
        while(index < word.size())
        {
            int index_child = word[index] - 'a';
            if(cur->_child[index_child] == nullptr)
            {
                return false;
            }

            cur = cur->_child[index_child];
            index++;
        }

        if(cur->_isChar)
        {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty())
        {
            return true;
        }

        Node* cur = _root;
        int index = 0;
        while(index < prefix.size())
        {
            int index_child = prefix[index] - 'a';
            if(cur->_child[index_child] == nullptr)
            {
                return false;
            }

            cur = cur->_child[index_child];
            index++;
        }

        //cur->_isChar = false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    set<int> arr {1,2,3,4,5,6,7};
    arr.erase(3);
    arr.erase(7);
    for(auto e : arr)
    {
       cout<<e<<" "; 
    }
    cout<<endl;
    return 0;
}
