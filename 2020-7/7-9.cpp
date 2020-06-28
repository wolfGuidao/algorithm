/*************************************************************************
  > File Name: 7-9.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月28日 星期日 14时18分56秒
 ************************************************************************/

#include "Header.hpp"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ret = 0;

int maxPathSumchild(TreeNode* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int left = max(0,maxPathSumchild(root->left));
    int right = max(0,maxPathSumchild(root->left));
    
    ret = max(ret,(left + right + root->val));

    return max(left,right) + root->val;
}


int main()
{
    pair<int,int> temp = {1,2};
    cout<<temp.first<<" : "<<temp.second<<endl;
    return 0;
}

