/*************************************************************************
# File Name: 8-25.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月27日 星期四 18时33分13秒
*************************************************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return false;
        }

        /*
        unordered_map<int,int> my_map;
        for(int i = 0;i < nums.size();i++)
        {
            if(my_map.count(nums[i]) >= 1)
            {
                return true;
            }

            my_map[nums[i]]++;

            if(my_map.size() > k)
            {
                my_map.erase(nums[i - k]);
            }
        }

        return false;
        */
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty())
        {
            return false;
        }

        for(int i = 0;i < nums.size();i++)
        {
            for(int j = max(i - k,0);j < i;j++)
            {
                if(abs((static_cast<long>(nums[i])) - (static_cast<long>(nums[j]))) <= t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
        //超时
        int ret = m;
        for(int i = m + 1;i <= n;i++)
        {
            ret = ret & i;
        }
        */

        /*
        //思想是：求二进制的公共前缀
        int ret = 0;
        //当他们相等的时候就是公共前缀
        while(m < n)
        {
            m = m >> 1;
            n = n >> 1;
            ret++;
        }

        //把位数补回来，即右边补0
        return m << ret;
        */

        //同理
        while(m < n)
        {
            n = n & (n - 1);
        }

        return n;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        /*
        for(int i = 0;i < s.size();i++)
        {
            if(s.find(s[i]) != t.find(t[i]))
            {
                return false;
            }
        }
        return true;
        */

        vector<int> s_map(256,-1);
        vector<int> t_map(256,-1);

        for(int i = 0;i < s.size();i++)
        {
            if(s_map[s[i]] != t_map[t[i]])
            {
                return false;
            }

            s_map[s[i]] = i;
            t_map[t[i]] = i;    
        }

        return true;
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
    int ret = 0;
    
    void NodeNum(TreeNode* root)
    {
        if(root)
        {
            ret++;
            NodeNum(root->left);
            NodeNum(root->right);
        }
    } 

    int countNodes(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }

        /*
        NodeNum(root);
        return ret;
        */

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
