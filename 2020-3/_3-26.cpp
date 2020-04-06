#include "Header.hpp"

// 单链表节点的结构
class ListNode 
{
  public:
  int val;
  ListNode* next;
  ListNode(int x) 
  { 
    val = x;  
  }
};

ListNode* Reverse(ListNode* root)
{
  if(root->next == nullptr)
  {
    return root;
  }
  ListNode* head = Reverse(root->next);
  root->next->next = root;
  root->next = nullptr;

  return head;
}

ListNode* success = nullptr;
ListNode* ReverseN(ListNode* root,int N)
{
  if(N == 1)
  {
    success = root->next;
    return root;
  }
  ListNode* head = ReverseN(root->next,N - 1);
  root->next->next = root;
  root->next = success;

  return head;

}

int main()
{
  return 0;
}
