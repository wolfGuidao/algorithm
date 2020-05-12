#include "Header.hpp"

enum Color 
{
  RED,
  BLACK
};

template<class T>
struct RBTreeNode
{
  RBTreeNode(const T& data = T(), const Color color = RED)
    :_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_pParent(nullptr)
     ,_color(color)
     ,_data(data)
  {

  }

  RBTreeNode<T>* _pLeft;
  RBTreeNode<T>* _pRight;
  RBTreeNode<T>* _pParent;
  Color _color;
  T _data;
};

template<class T>
class RBTree 
{
  typedef RBTreeNode<T> Node;

  public:
  RBTree()
    :_pHead(new Node())
  {

  }

  ~RBTree()
  {
    Destory(GetRoot());
  }

  bool Insert(const T& data)
  {
    Node* pRoot = GetRoot();
    if(pRoot == nullptr)
    {
      pRoot = new Node(data,BLACK);
      pRoot->_pParent = _pHead;
      _pHead->_pParent = pRoot;
    }
    else 
    {
      Node* cur = pRoot;
      Node* pParent = nullptr;
      while(cur)
      {
        pParent = cur;
        if(data > cur->_data)
        {
          cur = cur->_pRight;
        }
        else if(data < cur->_data)
        {
          cur = cur->_pLeft;
        }
        else 
        {
          return false;
        }
      }
      cur = new Node(data);
      if(cur->_data > pParent->_data)
      {
        pParent->_pRight = cur;
      }
      else if(cur->_data < pParent->_data)
      {
        pParent->_pLeft = cur;
      }

      cur->_pParent = pParent;

      while(pParent && pParent->_color == RED)
      {
        Node* pGand = pParent->_pParent;

        if(pParent == pGand->_pLeft)
        {
          Node* unclue = pGand->_pRight;
          if(unclue && unclue->_color == RED)
          {
            pParent->_color = BLACK;
            unclue->_color = BLACK;
            pGand->_color = RED;

            cur = pGand;
            pParent = cur->_pParent;
            printf("i am rbtree thing 1\n");
          }
          else 
          {
            if(cur == pParent->_pRight)
            {
              RotateL(pParent);
              swap(cur,pParent);
            }
            RotateR(pGand);
            pParent->_color = BLACK;
            pGand->_color = RED;
          }
        }
        else 
        {
          Node* unclue = pGand->_pRight;

          if(unclue && unclue->_color == RED)
          {
            pParent->_color = BLACK;
            unclue->_color = BLACK;
            pGand->_color = RED;

            cur = pGand;
            pParent = cur->_pParent;
          }
          else 
          {
            if(cur == pParent->_pLeft)
            {
              RotateR(pParent);
              swap(pParent,cur);
            }

            RotateL(pGand);
            pParent->_color = BLACK;
            pGand->_color = RED;            
          }
        }

      }


    }
    pRoot->_color = BLACK;
    _pHead->_pLeft = LeftMost();
    _pHead->_pRight = RightMost();
    printf("inset successful!!\n");
    return true;
  }

  bool IsValiedRBTree()
  {
    Node* Root = GetRoot();
    if(Root == nullptr)
    {
      printf("this is a rbtree\n");
      return true;
    }

    if(Root->_color != BLACK)
    {
      printf("this rbtree is bad of 1\n");
      return false;
    }

    size_t curBlackCount = 0;
    Node* cur = Root;
    while(cur)
    {
      if(BLACK == cur->_color)
      {
        curBlackCount++;
      }

      cur = cur->_pLeft;
    }

    size_t k = 0;
    return _IsValiedRBTree(Root,k,curBlackCount);
  }

  void Inorder()
  {
    Node* Root = GetRoot();
    _Inorder(Root);
    cout<<endl;
  }

  private:

  void _Inorder(Node* Root)
  {
    if(Root)
    {
      _Inorder(Root->_pLeft);
      printf("val:%d->",Root->_data);
      _Inorder(Root->_pRight);
    }
  }

  bool _IsValiedRBTree(Node* Root,size_t k,size_t BLACK_COUNT)
  {
    if(Root == nullptr)
    {
      printf("this rbtree is ok\n");
      return true;
    }
    else 
    {
      if(Root->_color == BLACK)
      {
        k++;
      }

      Node* pParent = Root->_pParent;
      if(pParent && pParent->_color == RED && pParent->_pParent->_color == RED)
      {
        printf("this a bad rbtree\n");
        return false;
      }
    }

    return _IsValiedRBTree(Root->_pLeft,k,BLACK_COUNT) && _IsValiedRBTree(Root->_pRight,k,BLACK_COUNT);
  }

  Node* LeftMost()
  {
    Node* Root = GetRoot();
    while(Root->_pLeft)
    {
      Root = Root->_pLeft;
    }

    return Root;
  }

  Node* RightMost()
  {
    Node* Root = GetRoot();
    while(Root->_pRight)
    {
      Root = Root->_pLeft;
    }

    return Root;
  }

  void RotateL(Node* pParent)
  {
    Node* pSubR = pParent->_pRight;
    Node* pSubRL = pSubR->_pLeft; 

    Node* ppParent = pParent->_pParent;

    pSubR->_pLeft = pParent;
    pParent->_pParent = pSubR;
    pParent->_pRight = pSubRL;
    if(pSubRL)
    {
      pSubRL->_pParent = pParent;  
    }

    if(ppParent == _pHead)
    {
      _pHead->_pParent = pSubR;
      pSubR->_pParent = _pHead;
    }
    else 
    {
      if(ppParent->_pLeft == pParent)
      {
        ppParent->_pLeft = pSubR;
      }
      else 
      {
        ppParent->_pRight = pSubR;
      }
      pSubR->_pParent = ppParent;
    }
  }


  void RotateR(Node* pParent)
  {
    Node* pSubL = pParent->_pLeft;
    Node* pSubLR = pSubL->_pRight; 

    Node* ppParent = pParent->_pParent;

    pSubL->_pRight = pParent;
    pParent->_pParent = pSubL;
    pParent->_pRight = pSubLR;
    if(pSubLR)
    {
      pSubLR->_pParent = pParent;  
    }

    if(ppParent == _pHead)
    {
      _pHead->_pParent = pSubL;
      pSubL->_pParent = _pHead;
    }
    else 
    {
      if(ppParent->_pLeft == pParent)
      {
        ppParent->_pLeft = pSubL;
      }
      else 
      {
        ppParent->_pRight = pSubL;
      }
      pSubL->_pParent = ppParent;
    }
  }

  void Destory(Node* root)
  {
    if(root)
    {
      Destory(root->_pLeft);
      Destory(root->_pRight);
      delete root;
      root = nullptr;
    }
  }

  Node* GetRoot()
  {
    return _pHead->_pParent;
  }

  Node* _pHead;
};


int main()
{
  RBTree<int> rbtree;
  rbtree.Insert(10);
  rbtree.Insert(5);
  rbtree.Insert(15);
  rbtree.Insert(8);
  rbtree.Insert(13);
  rbtree.Insert(0);
  rbtree.IsValiedRBTree();
  rbtree.Inorder();
  return 0;
}
