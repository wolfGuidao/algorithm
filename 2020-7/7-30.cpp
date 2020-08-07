/*************************************************************************
# File Name: 7-30.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月06日 星期四 16时50分51秒
*************************************************************************/
#include <iostream>
using namespace std;

#if 0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        int count = 31;
        while(count)
        {
            if(n & 1 == 1)
            {
                ret++;
            }
            n >> 1;
            count--;
        }
        return ret;
    }
};

int main()
{
    cout<<Solution().hammingWeight(9)<<endl;
    cout<<9 & 1<<endl;
    return 0;
}

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
    unordered_map<int,int> depth;
    unordered_map<int,TreeNode*> parent;

    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
        {
            return false;
        }

        dfs(root,nullptr);
        if(depth[x] == depth[y] && parent[x] != parent[y])
        {
            return true;
        }

        return false;
    }

    void dfs(TreeNode* root,TreeNode* cur)
    {
        if(root == nullptr)
        {
            return ;
        }

        if(cur == nullptr)
        {
            depth[root->val] = 0;
        }
        else 
        {
            depth[root->val] = depth[cur->val] + 1;
        }

        parent[root->val] = cur;
        dfs(root->left,root);
        dfs(root->right,root);
    }
};
#endif 

#if 0
class A
{
    public:
        virtual void Print()
        {
            cout<<"i am father"<<endl;
        }
};

class B : public A
{
    public:
        virtual void Print()
        {
            cout<<"i am child"<<endl;
        }
};

int main()
{
    B b;
    b.Print();
    b.A::Print();
    return 0;
}
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
    unordered_map<int,int> depth;
    unordered_map<int,TreeNode*> parent;

    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
        {
            return false;
        }

        /*
        dfs(root,nullptr);
        if(depth[x] == depth[y] && parent[x] != parent[y])
        {
            return true;
        }
        return false;
        */

        queue<TreeNode*> que;
        que.push(root);

        int flag = 2;
        while(!que.empty())
        {
            int Size = que.size();
            for(int i = 0;i < Size;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left && node->right && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x)))
                {
                    return false;
                }

                if(node->left)
                {
                    que.push(node->left);
                }

                if(node->right)
                {
                    que.push(node->right);
                }

                if(node->val == x || node->val == y)
                {
                    flag--;
                }
            }
            if(flag == 1)
            {
                return false;
            }
            else if(flag == 0)
            {
                return true;
            }

            flag = 2;
        }
        return false;   
    }

    void dfs(TreeNode* root,TreeNode* cur)
    {
        if(root == nullptr)
        {
            return ;
        }

        if(cur == nullptr)
        {
            depth[root->val] = 0;
        }
        else 
        {
            depth[root->val] = depth[cur->val] + 1;
        }

        parent[root->val] = cur;
        dfs(root->left,root);
        dfs(root->right,root);
    }
};
#endif 

#include <vector>
#include <algorithm>

int main()
{
    vector<int> arr {1,-1,2,4,-5,7,-9};
    for(auto e : arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    sort(arr.begin(),arr.end(),[](int a,int b)
            {
                return abs(a) < abs(b);
            });

    for(auto e : arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}

/*
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) 
    {
        if(A.empty())
        {
            return true;
        }

        vector<bool> flag(A.size(),false);
        sort(A.begin(),A.end(),[](int a,int b)
        {
            return abs(a) < abs(b);
        });

        unordered_map<int,int> index_map;
        //1 2 4 4 8 16
        //1 : 0
        //2 : 1
        //4 : 3
        //8 : 4
        //16 : 5
        bool ZERO = true;
        for(int i = 0;i < A.size();i++)
        {
            if(A[i] != 0)
            {
                ZERO = false;
            }
            index_map[A[i]] = i;
        }

        if(ZERO)
        {
            return true;
        }

        int count = 0;
        for(int i = 0;i < A.size();i++)
        {
            //1 2 4 4 8 16
            //1 : 0
            //2 : 1
            //4 : 3
            //8 : 4
            //16 : 5
            
            if(flag[i])
            {
                continue;
            }
            
            auto it = index_map.find(2 * A[i]);
            if(it == index_map.end())
            {
                return false;
            }

            int index = it->second;

            if(flag[index] == true)
            {
                return false;
            }
            //cout<<A[i]<<" : "<<A[index]<<endl;
            flag[i] = true;
            flag[index] = true;
            count++;
        }

        if(count != A.size() / 2)
        {
            return false;
        }
        return true;
    }
};
*/


class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int,int>m_map;
        for(auto i = 0;i < A.size();++i)
            m_map[A[i]]++;
        
        auto ite = m_map.begin();
        bool judge = true;
        while(ite != m_map.end())
        {
            if(ite->first < 0 && ite->second != 0)
            {
                m_map[(ite->first) / 2] -= ite->second;
                if(m_map[(ite->first) / 2] < 0)
                {
                    judge=false;
                    break;
                }
            }
           else if(ite->first == 0)
           {
                if(ite->second % 2 != 0)
                {
                   judge = false;
                   break;
                }
           }
           else if(ite->first > 0 && ite->second != 0)
           {
               m_map[(ite->first) * 2] -= ite->second;
                if(m_map[(ite->first) * 2] < 0)
                {
                   judge = false;
                   break;
                }
           }
           ite++; 
        }
        return judge;
    }
};

