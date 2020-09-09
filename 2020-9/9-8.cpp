/*************************************************************************
# File Name: 9-8.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月09日 星期三 10时28分05秒
*************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> sta;

        vector<int> count(256,0);

        for(auto& e : text)
        {
            count[e - '0']++;
        }

        vector<bool> instack(256,false);

        for(auto& e : text)
        {
            count[e - '0']--;
            if(instack[e - '0'] == true)
            {
                continue;
            }

            while(!sta.empty() && sta.top() > e)
            {
                if(count[sta.top() - '0'] == 0)
                {
                    break;
                }

                instack[sta.top() - '0'] = false;
                sta.pop();
            }
            sta.push(e);
            instack[e - '0'] = true;
        }

        string ret;
        while(!sta.empty())
        {
            ret += sta.top();
            sta.pop();
        }

        reverse(ret.begin(),ret.end());

        return ret;
    }
    };

int main()
{
    int a = 999;
    void* ptr = &a;
    void* test = (void*)malloc(256);

    return 0;
}

class Difference 
{
    public:
    Difference(vector<int> nums) 
    {
        assert(nums.size() > 0);
        diff.resize(nums.size(),0);

        // 构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) 
        {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i,j] 增加 val（可以是负数）*/
    void increment(int i, int j, int val) 
    {
        diff[i] += val;
        if (j + 1 < diff.size()) 
        {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() 
    {
        vector<int> ret(diff.size());
        
        // 根据差分数组构造结果数组
        ret[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) 
        {
            ret[i] = ret[i - 1] + diff[i];
        }
        return ret;
    }

    private:
    vector<int> diff;
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n,0);
        Difference df(nums);

        for(auto& e : bookings)
        {
            int i = e[0] - 1;
            int j = e[1] - 1;
            int val = e[2];
            df.increment(i,j,val);
        }

        return df.result();
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> ret;

    void dfs(TreeNode*& root,vector<int>& to_delete)
    {
        if(root == nullptr)
        {
            return ;
        }

        dfs(root->left,to_delete);
        dfs(root->right,to_delete);

        if(find(to_delete.begin(),to_delete.end(),root->val) != to_delete.end())
        {
            if(root->left)
            {
                ret.push_back(root->left);
            }

            if(root->right)
            {
                ret.push_back(root->right);
            }

            root = nullptr;
        }
        return ;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == nullptr)
        {
            return {};
        }

        dfs(root,to_delete);

        if(root)
            ret.push_back(root);

        return ret;
    }
};

