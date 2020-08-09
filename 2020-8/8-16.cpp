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
