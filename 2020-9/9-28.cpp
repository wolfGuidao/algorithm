/*************************************************************************
# File Name: 9-28.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年10月10日 星期六 19时51分36秒
*************************************************************************/
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
    void dfs(TreeNode* root,vector<int>& order)
    {
        if(root == nullptr)
            return;

        dfs(root->left,order);
        order.emplace_back(root->val);
        dfs(root->right,order);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
        {
            return 0;
        }

        vector<int> ret;
        dfs(root,ret);
        return ret[k - 1];
    }
};

