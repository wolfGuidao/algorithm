#include "Header.hpp"

template<class T>
struct AVLTreeNode 
{
  AVLTreeNode(const T& data = T())
    :_data(data)
     ,_bf(0)
     ,_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_pParent(nullptr)
  {}

  T _data;
  int _bf;
  AVLTreeNode<T>* _pLeft;
  AVLTreeNode<T>* _pRight;
  AVLTreeNode<T>* _pParent;
};

template<class T>
class AVLTree 
{
  typedef AVLTreeNode<T> Node;

  public:
  AVLTree()
    :_pRoot(nullptr)
  {}

  ~AVLTree()
  {
    _Destory(_pRoot);
  }

  bool Insert(const T& data)
  {
    if(_pRoot == nullptr)
    {
      _pRoot = new Node(data);
      printf("元素已经成功插入\n");
      return true;
    }

    Node* cur = _pRoot;
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
        printf("插入的元素已经存在\n");
        return false;
      }
    }

    cur = new Node(data);
    if(cur->_data < pParent->_data)
    {
      pParent->_pLeft = cur;
    }
    else if(cur->_data > pParent->_data) 
    {
      pParent->_pRight = cur;
    }

    cur->_pParent = pParent;

    while(pParent)
    {
      if(cur == pParent->_pLeft)
      {
        pParent->_bf -= 1;
      }
      else 
      {
        pParent->_bf += 1;
      }

      if(pParent->_bf == 0)
      {
        printf("插入新元素后父亲节点的平衡因子是0\n");
        return true;
      }
      else if(pParent->_bf == -1 || pParent->_bf == 1)
      {
        cur = pParent;
        pParent = pParent->_pParent;
      }
      else if(pParent->_bf == 2 || pParent->_bf == -2)
      {
        if(pParent->_bf == 2)
        {
          if(cur->_bf == 1)
          {
            RotateL(pParent);
          }
          else if(cur->_bf == -1)
          {
            RotateRL(pParent);
          }
        }
        else if(pParent->_bf == -2)
        {
          if(cur->_bf == 1)
          {
            RotateLR(pParent);
          }
          else if(cur->_bf == -1)
          {
            RotateR(pParent);
          }
        }
        break;
      }
    }
    printf("元素已经成功插入");
    return true;
  }

  void Inorder()
  {
    _Inorder(_pRoot);
  }

  void IsValiedAVLTree()
  {
    if(_IsValiedAVLTree(_pRoot))
    {
      printf("AVLTree is Ok!\n");
    }
    else 
    {
      printf("AVLTree is bad\n");
    }
  }

  private:

  void RotateL(Node* Root)
  {
    Node* pSubR = Root->_pRight;
    Node* pSubRL = pSubR->_pLeft;

    Root->_pRight = pSubRL;
    if(pSubRL)
    {
      pSubRL->_pParent = Root;
    }

    pSubR->_pLeft = Root;

    Node* ppParent = Root->_pParent;

    pSubR->_pParent = ppParent;
    Root->_pParent = pSubR;

    if(ppParent == nullptr)
    {
      _pRoot = pSubR;
    }
    else if(ppParent->_pLeft == Root)
    {
      ppParent->_pLeft = pSubR;
    }
    else 
    {
      ppParent->_pRight = pSubR;
    }

    ppParent->_bf = pSubR->_bf = 0;
    printf("左单旋完成\n");
  }

  void RotateR(Node* Root)
  {
    Node* pSubL = Root->_pLeft;
    Node* pSubLR = pSubL->_pRight;

    Root->_pLeft = pSubLR;
    if(pSubLR)
    {
      pSubLR->_pParent = Root;
    }

    pSubL->_pRight = Root;

    Node* ppParent = Root->_pParent;
    Root->_pParent = pSubL;
    pSubL->_pParent = ppParent;

    if(ppParent == nullptr)
    {
      _pRoot = pSubL;
    }
    else 
    {
      if(ppParent->_pLeft == Root)
      {
        ppParent->_pLeft = pSubL;
      }
      else 
      {
        ppParent->_pRight = pSubL;
      }
    }
    ppParent->_bf = pSubL->_bf = 0;
    printf("右单旋完成\n");
  }

  void RotateRL(Node* Root)
  {
    Node* pSubR = Root->_pRight;
    Node* pSubRL = pSubR->_pLeft;

    int bf = pSubRL->_bf;

    RotateR(pSubR);
    RotateL(Root);

    if(bf == 1)
    {
      Root->_bf = -1;
    }
    else 
    {
      pSubR->_bf = 1;
    }
    printf("右左双旋完成\n");
  }

  void RotateLR(Node* Root)
  {
    Node* pSubL = Root->_pLeft;
    Node* pSubRL = pSubL->_pRight;
    int bf = pSubRL->_bf;

    RotateL(Root->_pLeft);
    RotateR(Root);

    if(bf == 1)
    {
      pSubL->_bf = -1;

    }
    else if(bf == -1)
    {
      Root->_bf = 1;
    }
    printf("左右双旋完成\n");
  }

  void _Destory(Node* pRoot)
  {
    if(pRoot)
    {
      _Destory(pRoot->_pLeft);
      _Destory(pRoot->_pRight);
      delete pRoot;
      pRoot = nullptr;
    }
  }

  void _Inorder(Node* pRoot)
  {
    if(pRoot)
    {
      _Inorder(pRoot->_pLeft);
      printf("val:%d->",pRoot->_data);
      _Inorder(pRoot->_pRight);
    }
  }

  bool _IsValiedAVLTree(Node* pRoot)
  {
    if(nullptr == pRoot)
    {
      return true;

    }
    int leftHight = Hight(pRoot->_pLeft);
    int rightHight = Hight(pRoot->_pRight);
    int bf = rightHight - leftHight;

    if(abs(bf) <= 1 && bf == pRoot->_bf)
    {
      return _IsValiedAVLTree(pRoot->_pLeft) && _IsValiedAVLTree(pRoot->_pRight);

    }
    else 
    {
      return false;

    }
  }

  int Hight(Node* pRoot)
  {
    if(pRoot == nullptr)
    {
      return 0;

    }

    int leftHight = Hight(pRoot->_pLeft);
    int rightHight = Hight(pRoot->_pRight);

    return leftHight > rightHight ? leftHight + 1 : rightHight + 1;

  }

  Node* _pRoot;
};

int main()
{
  AVLTree<int> avltree;
  avltree.Insert(6);
  avltree.Insert(9);
  avltree.Insert(3);
  avltree.Insert(7);
  avltree.Insert(2);
  avltree.Inorder();
  avltree.IsValiedAVLTree();
  return 0;
}
