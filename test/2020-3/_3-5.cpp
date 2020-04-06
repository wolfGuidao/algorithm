#include "Header.hpp"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL)
  {}
};

int sum = 0;

int GetLength(TreeNode* root)
{
  if(root == nullptr)
  {
    return 0;
  }

  int Left = max(0,GetLength(root->left));
  int Right = max(0,GetLength(root->right));

  sum =max(sum,Left + Right + root->val);
  return max(Left , Right) + root->val;
}
