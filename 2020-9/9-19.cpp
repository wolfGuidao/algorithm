/*************************************************************************
# File Name: 9-19.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月24日 星期四 16时09分37秒
*************************************************************************/
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
    
    Node* connect(Node*& root) {
        if(root == nullptr)
        {
            return root;
        }

        //层序遍历 + 链接每一层的节点

        queue<Node*> _que;
        _que.push(root);
        while(!_que.empty())
        {
            int Size = _que.size();

            //层序遍历
            for(int i = 0;i < Size;i++)
            {
                Node* head = _que.front();
                _que.pop();

                //链接，每一层的最后一个节点不进行链接
                if(i + 1 < Size)
                {
                    head->next = _que.front();
                }

                if(head->left)
                {
                    _que.push(head->left);
                }

                if(head->right)
                {
                    _que.push(head->right);
                }

            }
        }
        return root;
    }
};
