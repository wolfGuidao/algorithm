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

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};


/*
class Solution {
public:
    Node* connect(Node* root) {
    	if(!root) return root;
    	queue<Node*> work;
        work.push(root);
    	work.push(nullptr);
    	Node* cur=nullptr;
    	while(1)
    	{
            if(work.front())    //队列首部是结点
            {
                cur=work.front();
    			work.pop();
                if(cur->left)   //非叶子结点
                {
                    work.push(cur->left);
    			    work.push(cur->right);
                }
    			cur->next=work.front();
            }
    		else if(work.size()==1) //只剩下一个nullptr结点
    			return root;
    		else    //遇到nullptr结点，这是一层的分割点
    		{
    			work.pop();
    			work.push(nullptr);
    		}
    	}

        return root;
    }
};
*/


class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        queue<Node*> q;
        Node* flag = new Node; // 用于记录每层树的结束。
        Node* last = new Node; // 用于记录上一个节点，将上一个节点的next连接当前节点。

        q.push(root); // 根推入队列
        q.push(flag); // 第一层结束，用flag标记位置
        while(q.size() >= 2){ //队列内到最后存在一个flag，因此 >2
            Node* now = q.front(); // 取出当前节点。
            q.pop();
            if(now == flag){ // 如果到达每层末尾，last清空，再次推入flag
                //last -> next = NULL;
                last = NULL;
                q.push(flag);
                continue;
            }
            if(last == NULL){ // 说明是新的一层
                last = now; 
            }
            else{ // 否则一定存在last节点
                last -> next = now;
                last = now; // 更新last节点
            }
            if(now -> left){ //压入新的节点。
                q.push(now -> left);
                q.push(now -> right);
            }
        }
        return root; 
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(unordered_map<int,Employee*> emp_map, int id)
    {
        auto it = emp_map.find(id);
        if(it == emp_map.end())
        {
            return 0;
        }

        int sum = 0;
        Employee* emp = emp_map[id];
        sum += emp->importance;
        for(auto e : emp->subordinates)
        {
            sum += dfs(emp_map,e);
        }

        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
        {
            return 0;
        }

        unordered_map<int,Employee*> emp_map;
        for(auto e : employees)
        {
            emp_map[e->id] = e;
        }

        return dfs(emp_map,id);
    }
};
