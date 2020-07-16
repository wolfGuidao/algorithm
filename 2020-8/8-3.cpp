/*************************************************************************
# File Name: 8-3.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月15日 星期三 19时33分22秒
*************************************************************************/

//评测题目: 按段（段内的元素不翻转）翻转链表：如链表 1->2->3->4->5->6->7->8->9，如果段大小为3，翻转后为7->8->9->4->5->6->1->2->3。注意段大小作为参数传入。要求编写可以运行的测试用例。
#include <iostream>
#include <vector>
using namespace std;

struct Node 
{
  	Node(int data)
      :_data(data)
        ,next(nullptr)
        {}
  
	int _data;
	Node* next;
};

//翻转整个链表
Node* ReverseChild(Node*& root)
{
	if(root->next == nullptr)
    {
    	return root;
    }
  
  	Node* last = ReverseChild(root->next);
  	root->next->next = root;
  	root->next = nullptr;
    
  	return last;
}

//翻转start和end区间内的链表
void ReverseOfKChild(Node*& start,Node*& end)
{
  	if(start == nullptr)
    {
      	return ;
    }
  
  	Node* pre = nullptr;
  
  	while(start != nullptr)
    {
      	Node* Next = start->next;
      
      	start->next = pre;
      
      	pre = start;
      
      	if(Next == nullptr || start == end)
        {
          	break;
        }
      
      	start = Next;
    }
  
  return ;
}

//翻转K个一翻转
Node* ReverseOfK(Node* root,int k)
{
  	if(k == 0)
    {
      	return root;
    }
  
  	Node* fast = root;
  	Node* pre = nullptr;
  	Node* head = nullptr;
  
  	while(fast != nullptr)
    {
      	int t = k;
      	Node* slow = fast;
      	while(t > 1)
        {
          	if(fast->next == nullptr)
            {
              	break;
            }
          
          	fast = fast->next;
          	
          	t--;
        }
      
      	if(head == nullptr) 
        {
          	head = fast;
        }
      
      	Node* temp = fast->next;
      	
      	ReverseOfKChild(slow,fast);
      
      	slow->next = temp;
      
      	if(pre != nullptr)
        {
          	pre->next = fast;
        }
      
      	pre = slow;
      	fast = temp;
    }
  return head;
}

//本题的入口函数
Node* Reverse(Node*& root,int k)
{
	if(root == nullptr)
    {
    	return nullptr;
    }
  
  	//9->8->7....->1
  	//7->8->9....->1->2->3
  	Node* last = ReverseChild(root);
  
  	Node* head = ReverseOfK(last,k);
  
  	return head;
}

void Print(Node* root)
{
  	if(root)
    {
      	printf("%d->\n",root->_data);
      	root = root->next;
    }
}

int main()
{
  	vector<int> arr {1,2,3,4,5,6,7,8,9};
  	
  	Node* root = nullptr;
  	Node* tail = nullptr;
  	for(size_t i = 0;i < arr.size();i++)
    {
      	if(root == nullptr)
        {
          	root = new Node(arr[i]);
          	tail = root;
        }
      
      	Node* temp = new Node(arr[i]);
      	tail->next = temp;
      	tail = tail->next;
    }
  
  	int k = 3;
  
  	Print(root);
  	Node* head = Reverse(root,k);
  	Print(head);
  	
  	return 0;
}
