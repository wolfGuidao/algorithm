#include "Header.hpp"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Build(vector<int>::iterator prebegin,vector<int>::iterator preend,vector<int>::iterator inobegin,vector<int>::iterator inoend)
{
  if(inobegin == inoend)
  {
    return nullptr;
  }

  TreeNode* root = new TreeNode(*prebegin);
  auto cur = find(inobegin,inoend,*prebegin);

  root->left = Build(prebegin + 1,prebegin + (cur - inobegin)+ 1,inobegin,cur);
  root->right = Build(prebegin + 1 + (cur - inobegin),preend,cur + 1,inoend);

  return root;
}


void Print(TreeNode*& root)
{
  if(root == nullptr)
  {
    return;
  }
  Print(root->left);
  cout<<root->val<<"->";
  Print(root->right);
}

int main()
{
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  TreeNode* root = Build(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
  Print(root);
  return 0;
}
