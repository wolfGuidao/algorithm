#include "Header.hpp"

//二叉树的三种遍历方式非递归
//主要思想就是用栈模拟递归
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//前序
class Solution1 
{
  public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
      vector<int> ret;//保存结果
      stack<TreeNode*>s;//模拟递归

      TreeNode* cur = root;//开始遍历
      while(!s.empty() || cur)
      {
        while(cur)//该循环是每次往左递归压栈，同时保存根节点
        {
          ret.push_back(cur->val);//前序在递归压栈往左边找的时候先保存结果
          s.push(cur);
          cur = cur->left;
        }

        //这里索命cur为空，代表走到二叉树的最左边，所以取cur的父亲节点，遍历夫亲节点的右子树
        TreeNode* Right = s.top();
        s.pop();
        cur = Right->right;
      }
      return ret;
    }
};

class Solution2 
{
  public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
      vector<int> ret;
      stack<TreeNode*>s;
      TreeNode* cur = root;
      while(!s.empty() || cur)
      {
        while(cur)
        {
          s.push(cur);
          cur = cur->left;
        }

        TreeNode* Right = s.top();
        s.pop();
        ret.push_back(Right->val);//找到最左边的节点后，先放左子树节点，再放跟节点，最后放右子树节点
        cur = cur->right;
      }
      return ret;
    }
};

class Solution3 
{
  public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
      vector<int> ret;
      stack<TreeNode*> s;
      TreeNode* cur = root;
      TreeNode* flag = nullptr;
      while(!s.empty() || cur)
      {
        while(cur)
        {
          s.push(cur);
          cur = cur->left;
        }

        //前面的思路一致，后序遍历是先放左子树节点，再放右子树节点，最后放根节点
        TreeNode* Right = s.top();//取出最左边的节点
        //当最左边的节点为空或者被flag标记时才可以把当前跟节点放入到ret当中，否则就说明当前根节点还有右子树，需要往又继续判断
        if(Right->right == nullptr || Right->right == flag)
        {
          ret.push_back(Right->val);
          flag = Right;
          s.pop();
        }
        else 
        {
          cur = cur->right;
        }

      }
    }
};

int main()
{
  return 0;
}
