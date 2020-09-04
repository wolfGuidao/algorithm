/*************************************************************************
# File Name: 9-2.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月04日 星期五 20时06分29秒
*************************************************************************/

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
    vector<int> ret;
    void dfs(TreeNode* root,string str)
    {
        if(root != nullptr)
        {
            str += to_string(root->val);

            if(root->left == nullptr && root->right == nullptr)
            {
                //cout<<str<<endl;
                ret.push_back(stoi(str));
            }
            
            dfs(root->left,str);
            dfs(root->right,str);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }

        dfs(root,"");

        int res = 0;

        for(auto& e : ret)
        {
            res += e;
        }

        return res;
    }
};
