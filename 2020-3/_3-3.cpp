/*nition for a binary tree node.
 * struct TreeNode {
 *  *     int val;
 *   *     TreeNode *left;
 *    *     TreeNode *right;
 *     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *      * };
 *       */

class Solution {
  public:
    vector<int> dp(TreeNode* root) {
      if (root == nullptr)
      {
        return vector<int>(2,0);

      }

      vector<int> left = dp(root->left);
      vector<int> right = dp(root->right);

      // 抢， 下家就不能抢了
      int rob = root->val + left[0] + right[0];

      // 不抢， 下家可抢可不抢， 取决于收益⼤⼩,注意他是二叉树的结构，所以还要返回两种情况之和
      int not_rob = max(left[0], left[1])
        + max(right[0], right[1]);

      return vector<int>{not_rob,rob};

    }
    int rob(TreeNode* root) {
      vector<int> ret = dp(root);

      return max(ret[0], ret[1]);

    }

};

