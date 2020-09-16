/*************************************************************************
# File Name: 9-13.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月15日 星期二 11时33分37秒
*************************************************************************/
/*
class Solution {
public:
    bool IsTrue(char ch)
    {
        if(ch >= '0' && ch <= '9')
        {
            return true;
        }
        return false;
    }

    int myAtoi(string str) {
        //判空
        if(str.empty() || str == "")
        {
            return 0;
        }

        int index = 0;

        //处理空格
        while(index < str.size() && str[index] == ' ')
        {
            index++;
        }

        //全都是空格的情况
        if(index == str.size())
        {
            return 0;
        }

        //处理正负号
        int flag = 1;
        if(str[index] == '+')
        {
            index++;
        }
        else if(str[index] == '-') 
        {
            flag = -1;
            index++;
        }
        //第一个不是数字的情况
        else if(IsTrue(str[index]) == false)
        {
            return 0;
        }
        
        //保存结果
        long long ret = 0;
        while(index < str.size())
        {
            //处理数字的情况
            if(IsTrue(str[index]) == true)
            {
                //2147483647
                //处理溢出
                if(ret > INT_MAX)
                {
                    break;
                }

                ret *= 10;
                ret += (str[index] - '0');
            }
            else 
            {
                break;
            }

            index++;
        }

        ret *= flag;
        //处理溢出情况
        if(ret > INT_MAX)
        {
            ret = INT_MAX;
        }
        else if(ret < INT_MIN)
        {
            ret = INT_MIN;
        }
        
        return ret;
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        int prev = 0;
        int cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur] != 0)
            {
                swap(nums[cur],nums[prev]);
                cur++;
                prev++;
            }
            else 
            {
                cur++;
            }
        }
        */

        /*
        vector<int> arr(nums.size(),0);
        int index = 0;
        for(auto& e : nums)
        {
            if(e != 0)
            {
                arr[index++] = e;
            }
        }

        nums = arr;
        */

        int index = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != 0)
            {
                nums[index++] = nums[i];
            }
        }

        for(;index < nums.size();index++)
        {
            nums[index] = 0;
        }
    }
};

#include <iostream>
using namespace std;

class Test 
{
    public:
        int x;
        int y;
        int z;
};

int main()
{
    Test* test = NULL;
    int* offset = (int*)(&(test->z));
    cout<<offset - NULL<<endl;
    return 0;
}


class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> my_map;

        //记录位子和字符相等的元素的个数  
        int count_a = 0;
        for(int i = 0;i < secret.size();i++)
        {
            my_map[secret[i]]++;
            if(secret[i] == guess[i])
            {
                count_a++;
            }
        }

        //元素个数满足的情况
        int count_b = 0;
        for(auto& e : guess)
        {
            if(my_map[e] > 0)
            {
                count_b++;
                my_map[e]--;
            }
        }

        //需要减去位子刚好满足的情况
        count_b -= count_a;

        //组织结果
        string ret = "";
        ret += to_string(count_a);
        ret += 'A';
        ret += to_string(count_b);
        ret += 'B';
        return ret;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
        {
            return ;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* Left = root->left;
        TreeNode* Right = root->right;

        root->left = nullptr;
        root->right = Left;

        TreeNode* cur = root;
        while(cur->right)
        {
            cur = cur->right;
        }
        cur->right = Right;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectChild(Node* node1,Node* node2)
    {
        if(node1 == nullptr || node2 == nullptr)
        {
            return ;
        }

        //链接节点
        node1->next = node2;

        //链接同一个父亲节点的左右孩子
        connectChild(node1->left,node1->right);
        connectChild(node2->left,node2->right);

        //链接不同父亲孩子
        connectChild(node1->right,node2->left);
    }

    Node* connect(Node* root) {
        if(root == nullptr)
        {
            return root;
        }   

        connectChild(root->left,root->right);

        return root;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() != cost.size() || gas.empty() || cost.empty())
        {
            return -1;
        }

        int start = 0;
        int sum = 0;
        int cur = 0;
        for(int i = 0;i < gas.size();i++)
        {
            sum += (gas[i] - cost[i]);
            cur += (gas[i] - cost[i]);
            if(cur < 0)
            {
                start = i + 1;
                cur = 0;
            }
        }

        if(sum < 0)
        {
            return -1;
        }

        return start;
    }
};
