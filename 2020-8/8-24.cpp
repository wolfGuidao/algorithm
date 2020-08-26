/*************************************************************************
# File Name: 8-24.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月26日 星期三 19时37分10秒
 *************************************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

#if 0
typedef struct Node 
{
    int data;

    //跳表结点的前后和上下都有指针
    Node* up;
    Node* down;
    Node* left;
    Node* right;

    Node(int val) 
        :data(val)
         ,up(nullptr)
         ,down(nullptr)
         ,left(nullptr)
         ,right(nullptr)
    {
    }
}Node;

class SkipList
{

    public:
    SkipList() 
    {
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->right = tail;
        tail->left = head;
    }

    //查找结点
    Node* search(int data)
    {
        Node* p= findNode(data);
        if(p->data == data)
        {
            printf("找到结点：%d",data);
            return p;
        }
        printf("未找到结点：%d",data);
        return nullptr;
    }

    //找到值对应的前置结点
    Node* findNode(int data)
    {
        Node* node = head;
        while(true)
        {
            while (node->right->data != INT_MAX && node->right->data <= data) 
            {
                node = node->right;
            }

            if (node->down == nullptr) 
            {
                break;
            }

            node = node->down;
        }
        return node;
    }

    //插入结点
    void insert(int data)
    {
        Node* preNode= findNode(data);
        //如果data相同，直接返回
        if (preNode->data == data) 
        {
            return;
        }

        Node* node = new Node(data);
        appendNode(preNode, node);
        int currentLevel=0;
        //随机决定结点是否“晋升”
        Random random = new Random();
        while (random.nextDouble() < PROMOTE_RATE) {
            //如果当前层已经是最高层，需要增加一层
            if (currentLevel == maxLevel) {
                addLevel();
            }
            //找到上一层的前置节点
            while (preNode.up==null) {
                preNode=preNode.left;
            }
            preNode=preNode.up;
            //把“晋升”的新结点插入到上一层
            Node upperNode = new Node(data);
            appendNode(preNode, upperNode);
            upperNode.down = node;
            node.up = upperNode;
            node = upperNode;
            currentLevel++;
        }
    }

    //在前置结点后面添加新结点
    private void appendNode(Node preNode, Node newNode){
        newNode.left=preNode;
        newNode.right=preNode.right;
        preNode.right.left=newNode;
        preNode.right=newNode;
    }

    //增加一层
    private void addLevel(){
        maxLevel++;
        Node p1=new Node(Integer.MIN_VALUE);
        Node p2=new Node(Integer.MAX_VALUE);
        p1.right=p2;
        p2.left=p1;
        p1.down=head;
        head.up=p1;
        p2.down=tail;
        tail.up=p2;
        head=p1;
        tail=p2;
    }

    //删除结点
    public boolean remove(int data){
        Node removedNode = search(data);
        if(removedNode == null){
            return false;
        }

        int currentLevel=0;
        while (removedNode != null){
            removedNode.right.left = removedNode.left;
            removedNode.left.right = removedNode.right;
            //如果不是最底层，且只有无穷小和无穷大结点，删除该层
            if(currentLevel != 0 && removedNode.left.data == Integer.MIN_VALUE && removedNode.right.data == Integer.MAX_VALUE){
                removeLevel(removedNode.left);
            }else {
                currentLevel ++;
            }
            removedNode = removedNode.up;
        }

        return true;
    }

    //删除一层
    private void removeLevel(Node leftNode){
        Node rightNode = leftNode.right;
        //如果删除层是最高层
        if(leftNode.up == null){
            leftNode.down.up = null;
            rightNode.down.up = null;
        }else {
            leftNode.up.down = leftNode.down;
            leftNode.down.up = leftNode.up;
            rightNode.up.down = rightNode.down;
            rightNode.down.up = rightNode.up;
        }
        maxLevel --;
    }

    //输出底层链表
    public void printList() {
        Node node=head;
        while (node.down != null) {
            node = node.down;
        }
        while (node.right.data != Integer.MAX_VALUE) {
            System.out.print(node.right.data + " ");
            node = node.right;
        }
        System.out.println();
    }

    //链表结点类

    public static void main(String[] args) {
        SkipList list=new SkipList();
        list.insert(50);
        list.insert(15);
        list.insert(13);
        list.insert(20);
        list.insert(100);
        list.insert(75);
        list.insert(99);
        list.insert(76);
        list.insert(83);
        list.insert(65);
        list.printList();
        list.search(50);
        list.remove(50);
        list.search(50);
    }
    private:
    //结点“晋升”的概率
    double PROMOTE_RATE = 0.5;
    Node* head;
    Node* tail;
    int maxLevel;
};
#endif 

#include <memory>
struct ListNode
{
	int _data;
	shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
};

int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}

