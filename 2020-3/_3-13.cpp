/*
 * struct TreeNode {
 *  int val;
 *    struct TreeNode *left;
 *      struct TreeNode *right;
 *        TreeNode(int x) :
 *              val(x), left(NULL), right(NULL) {
 *                }
 *                };*/

class Solution {
  public:
    void Tranlate(TreeNode* pRoot,TreeNode*& Head)
    {
      if(pRoot == nullptr)
      {
        return ;

      }

      //往左变递归
      if(pRoot->left)
        Tranlate(pRoot->left,Head);

      //拿到最左边的节点，把当前节点的left指针指向Head
      pRoot->left = Head;

      //Head是有可能为空的，所以需要判断
      //Head为真就需要改变上一个节点的right指针，让其指向当前节点
      if(Head)
      {
        Head->right = pRoot;
      }

      //更新Head节点
      Head = pRoot;

      //递归右边
      if(pRoot->right)
        Tranlate(pRoot->right,Head);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
      if(!pRootOfTree)
      {
        return nullptr;
      }

      TreeNode* Head = nullptr;
      Tranlate(pRootOfTree,Head);

      //把Head指向链表的开始
      while(Head->left)
      {
        Head = Head->left;
      }
      return Head;
    }
};

/*
   class Solution {
   public:
   void convert2List(TreeNode* pRoot,TreeNode *&pointer)
   {
   if (pRoot == NULL)
   {
   return;
   }
   {
   if (pRoot->left != NULL)
   {
   convert2List(pRoot->left,pointer);
   }

   pRoot->left = pointer;
   if (pointer != NULL)
   {
   pointer->right = pRoot;
   }

   pointer = pRoot;
   if (pRoot->right!=NULL)
   {
   convert2List(pRoot->right, pointer);
   }
   }
   }
   TreeNode* Convert(TreeNode* pRootOfTree)
   {
   if (pRootOfTree == NULL)return NULL;
   TreeNode *pointer = NULL;
   convert2List(pRootOfTree, pointer);
   while (pointer->left!=NULL)
   {
   pointer = pointer->left;
   }
   return pointer;
   }

   };
   */

}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
*            }
* }
