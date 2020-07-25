/*************************************************************************
# File Name: 8-3.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月15日 星期三 19时33分22秒
 *************************************************************************/

//评测题目: 按段（段内的元素不翻转）翻转链表：如链表 1->2->3->4->5->6->7->8->9，如果段大小为3，翻转后为7->8->9->4->5->6->1->2->3。注意段大小作为参数传入。要求编写可以运行的测试用例。
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;

//struct Node 
//{
//    Node(int data)
//        :_data(data)
//         ,next(nullptr)
//    {}
//
//    int _data;
//    Node* next;
//};
//
////翻转整个链表 OK 
//Node* ReverseChild(Node*& root)
//{
//    if(root->next == nullptr)
//    {
//        return root;
//    }
//
//    Node* last = ReverseChild(root->next);
//    root->next->next = root;
//    root->next = nullptr;
//
//    return last;
//}
//
////翻转start和end区间内的链表 OK 
//void ReverseOfKChild(Node* start,Node* end)
//{
//    if(start == nullptr)
//    {
//        return ;
//    }
//
//    //保存上一个节点
//    Node* pre = nullptr;
//
//    //保存下一个节点
//    Node* Next = nullptr;
//    while(start != nullptr)
//    {
//        //if的作用防止空指针的问题
//        if(Next != end)
//            Next = start->next;
//
//        //把下一个节点和上一个节点连接起来
//        start->next = pre;
//
//        //更新上一个结点的位置
//        pre = start;
//
//        //代表start指针已经走到末尾，可以直接结束循环
//        if(Next == nullptr || start == end)
//        {
//            break;
//        }
//
//        //把start放到提前保存的Next处
//        start = Next;
//    }
//
//    return ;
//}
//
//
//#if 1
////翻转K个一翻转
//Node* ReverseOfK(Node* root,int k)
//{
//    if(k == 0)
//    {
//        return root;
//    }
//
//    //保存记录每个K段的末尾处
//    Node* fast = root;
//
//    //这个变量的作用是非常非常非常非常重要的，他是把每个K段的连表连接起来
//    Node* pre = nullptr;
//
//    //翻转后的头节点
//    Node* head = nullptr;
//
//    //循环遍历
//    while(fast != nullptr)
//    {
//        int t = k;
//        //记录每个K段的开始位置
//        Node* slow = fast;
//
//        //找到每个K段的末尾位置
//        while(t > 1)
//        {
//            if(fast->next == nullptr)
//            {
//                break;
//            }
//
//            fast = fast->next;
//
//            t--;
//        }
//
//        //保存头结点
//        if(head == nullptr) 
//        {
//            head = fast;
//        }
//
//        //记录每个K段末尾节点的下一个节点，因为一旦前面的发生翻转，那么如果不保存就找不到了
//        Node* temp = fast->next;
//
//        //翻转slow和fast区间的节点，该该函数一定不要引用传参，因为在内部会改变slow
//        ReverseOfKChild(slow,fast);
//
//        //把每个K段的开始位置（经过翻转后是每个K段的结束位置）和提前保存的temp相连，把相邻的K段节点构成一个链 
//        slow->next = temp;
//
//        if(pre != nullptr)
//        {
//            pre->next = fast;
//        }
//
//        //记录上一个slow的位置
//        pre = slow;
//
//        //把fast放到提前保存的节点处
//        fast = temp;
//    }
//    return head;
//}
//#endif
//
//
////本题的入口函数
//Node* Reverse(Node*& root,int k)
//{
//    if(root == nullptr)
//    {
//        return nullptr;
//    }
//
//    //9->8->7....->1
//    //7->8->9....->1->2->3
//    Node* last = ReverseChild(root);
//
//    Node* head = ReverseOfK(last,k);
//
//    return head;
//}
//
//void Print(Node* root)
//{
//    Node* cur = root;
//    while(cur)
//    {
//        printf("%d->\n",cur->_data);
//        cur = cur->next;
//    }
//}
//
//int main()
//{
//    vector<int> arr {1,2,3,4,5,6,7,8,9,10,11};
//
//    Node* root = nullptr;
//    Node* tail = nullptr;
//    for(size_t i = 0;i < arr.size();i++)
//    {
//        if(root == nullptr)
//        {
//            root = new Node(arr[i]);
//            tail = root;
//            continue;
//        }
//
//        Node* temp = new Node(arr[i]);
//        tail->next = temp;
//        tail = tail->next;
//    }
//
//    int k = 3;
//
//    Print(root);
//    cout<<endl;
//    Node* head = Reverse(root,k);
//    //Node* head = ReverseChild(root);
//    //ReverseOfKChild(root,tail);
//    //Node* head = ReverseOfK(root,k);
//    Print(head);
//
//    return 0;
//}

class MaxGap {
    public:
        int findMaxGap(vector<int> A, int n) {
            // write code here
            stack<int> right_to_left;

            for(int i = n - 1;i > 0;i--)
            {
                if(right_to_left.top() > A[i])
                {
                    continue;
                }

                right_to_left.push(A[i]);
            }

            int ret = 0;
            int left = INT_MIN;
            for(int k = 0;k <= n - 2;k++)
            {
                //[0,k]
                //[k + 1,N - 1]
                left = max(left,A[k]);

                if(right_to_left.top() == A[k])
                {
                    if(!right_to_left.empty())
                        right_to_left.pop();
                }

                ret = max(ret,abs(left - right_to_left.top()));
            }

            return ret;
        }
};

class Printer {
    public:
        vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
            // write code here
            vector<vector<bool>> visted(n,vector<bool>(m,false));

            vector<int> ret;
            int count = n * m;

            int i = 0;
            int j = 0;
            while(count)
            {
                cout<<count<<endl;
                cout<<"i: "<<i<<" j: "<<j<<endl;
                while(j < m && visted[i][j] == false)
                {
                    ret.push_back(mat[i][j]);
                    count--;
                    cout<<count<<endl;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    visted[i][j] = true;
                    j++;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                }

                cout<<"i: "<<i<<" j: "<<j<<endl;
                j--;
                i++;
                cout<<"i: "<<i<<" j: "<<j<<endl;

                while(i < n && visted[i][j] == false)
                {
                    ret.push_back(mat[i][j]);
                    count--;
                    cout<<count<<endl;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    visted[i][j] = true;
                    i++;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                }

                cout<<"i: "<<i<<" j: "<<j<<endl;
                i--;
                j--;

                cout<<"i: "<<i<<" j: "<<j<<endl;
                while(j >= 0 && visted[i][j] == false)
                {
                    ret.push_back(mat[i][j]);
                    count--;
                    cout<<count<<endl;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    visted[i][j] = true;
                    j--;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                }

                cout<<"i: "<<i<<" j: "<<j<<endl;
                j++;
                i--;

                cout<<"i: "<<i<<" j: "<<j<<endl;
                while(i >= 0 && visted[i][j] == false)
                {
                    ret.push_back(mat[i][j]);
                    count--;
                    cout<<count<<endl;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    visted[i][j] = true;
                    i--;
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                }
            }
            return ret;
        }
};

int main()
{
    vector<vector<int>> arr {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ret = Printer().clockwisePrint(arr,3,3);

    for(auto e : ret)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
