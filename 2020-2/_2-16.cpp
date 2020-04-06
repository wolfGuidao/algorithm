#include "Header.hpp"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_ = INT_MIN;
int maxPathSumchild(TreeNode* root)
{
  if(root == nullptr)
  {
    return 0;
  }

  int left = max(0,maxPathSumchild(root->left));
  int right = max(0,maxPathSumchild(root->right));

  max_ = max(max_,left + right + root->val);

  return max(left,right) + root->val;
}

int main()
{
  return 0;
}
