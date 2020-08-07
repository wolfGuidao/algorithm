/*************************************************************************
# File Name: 7-30.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月06日 星期四 16时50分51秒
*************************************************************************/
#include <iostream>
using namespace std;

#if 0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        int count = 31;
        while(count)
        {
            if(n & 1 == 1)
            {
                ret++;
            }
            n >> 1;
            count--;
        }
        return ret;
    }
};

int main()
{
    cout<<Solution().hammingWeight(9)<<endl;
    cout<<9 & 1<<endl;
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> depth;
    unordered_map<int,TreeNode*> parent;

    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
        {
            return false;
        }

        dfs(root,nullptr);
        if(depth[x] == depth[y] && parent[x] != parent[y])
        {
            return true;
        }

        return false;
    }

    void dfs(TreeNode* root,TreeNode* cur)
    {
        if(root == nullptr)
        {
            return ;
        }

        if(cur == nullptr)
        {
            depth[root->val] = 0;
        }
        else 
        {
            depth[root->val] = depth[cur->val] + 1;
        }

        parent[root->val] = cur;
        dfs(root->left,root);
        dfs(root->right,root);
    }
};
#endif 

class A
{
    public:
        virtual void Print()
        {
            cout<<"i am father"<<endl;
        }
};

class B : public A
{
    public:
        virtual void Print()
        {
            cout<<"i am child"<<endl;
        }
};

int main()
{
    B b;
    b.Print();
    b.A::Print();
    return 0;
}
