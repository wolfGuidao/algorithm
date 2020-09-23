/*************************************************************************
# File Name: 9-17.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月23日 星期三 21时21分49秒
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
    void connectChild(Node*& node1,Node*& node2)
    {
        if(node1 == nullptr || node2 == nullptr)
        {
            return ;
        }

        node1->next = node2;
        connectChild(node1->left,node1->right);
        connectChild(node2->left,node2->right);

        if(node1->right && node2->left)
            connectChild(node1->right,node2->left);
        else if(node1->right == nullptr && node1->left && node2->right && node2->left == nullptr)
            connectChild(node1->left,node2->right);
        else if(node1->right == nullptr && node1->left && node2->left)
            connectChild(node1->left,node2->left);
        else if(node1->right && node2->left == nullptr && node2->right)
            connectChild(node1->right,node2->right);

    }

    Node* connect(Node*& root) {
        if(root == nullptr)
        {
            return root;
        }

        connectChild(root->left,root->right);

        return root;
    }
};
