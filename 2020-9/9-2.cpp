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
    vector<vector<int>> res;   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level)
    {
        if(root == NULL)    
            return;

        if(res.size() == level)       
            res.resize(level + 1);    //level表示层数，也对应二维数组的第一层索引

        if(level % 2 == 0)                                     
            res[level].push_back(root->val);//如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面
        else
            res[level].insert(res[level].begin(),root->val);

        addVector(root->left,level + 1);
        addVector(root->right,level + 1);          
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;

        // 维护一个计数器记录字符串中字符的数量
        // 因为输入为 ASCII 字符，大小 256 够用了
        vector<int> count(256,0);
        for (int i = 0; i < s.size(); i++) 
        {
            count[s[i]]++;
        }

        vector<bool> inStack(256,false);
        for (char& c : s) 
        {
            // 每遍历过一个字符，都将对应的计数减一
            count[c]--;

            if (inStack[c]) 
        	    continue;

            while (!stk.empty() && stk.top() > c) 
            {
                // 若之后不存在栈顶元素了，则停止 pop
                if (count[stk.top()] == 0) 
                {
                    break;
                }
                // 若之后还有，则可以 pop
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }

        string ret;
        while (!stk.empty()) 
        {
            ret += stk.top();
            stk.pop();
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};


