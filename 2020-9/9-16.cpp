/*************************************************************************
# File Name: 9-16.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月22日 星期二 14时27分12秒
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
    int FindMaxIndex(vector<int>& nums,int left,int right)
    {
        int index = left;
        int val = INT_MIN;
        for(int i = left;i <= right;i++)
        {
            if(nums[i] > val)
            {
                val = nums[i];
                index = i;
            }
        }

        return index;
    }

    TreeNode* Create(vector<int>& nums,int left,int right)
    {
        if(left <= right)
        {
            int index = FindMaxIndex(nums,left,right);
            TreeNode* root = new TreeNode(nums[index]);
            root->left = Create(nums,left,index - 1);
            root->right = Create(nums,index + 1,right);

            return root;
        }
        
        return nullptr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
        {
            return nullptr;
        }

        return Create(nums,0,nums.size() - 1);
    }
};
