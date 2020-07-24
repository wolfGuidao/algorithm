/*************************************************************************
# File Name: 8-10.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月24日 星期五 15时04分34秒
*************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 0
class cmp 
{
    public:
    bool operator()(int l,int r)
    {
        return l > r;
    }
};

int main()
{
    priority_queue<int,vector<int>,cmp> que;
    for(int i = 1;i <= 10;i++)
    {
        que.push(i);
    }
    cout<<que.top()<<endl;
    return 0;
}
#endif

struct Node 
{
    Node(int val)
        :_val(val)
    {}

    //bool operator<(const Node& l) const
    //{
    //    return _val > l._val;
    //}

    //bool operator>(const Node& l) const 
    //{
    //    return _val < l._val;
    //}

    int _val;
};

class cmp 
{
    public:
        bool operator()(Node l,Node r)const 
        {
            return l._val > r._val;
        }
};

int main()
{
    priority_queue<Node,vector<Node>,cmp> que;
    for(int i = 1;i <= 10;i++)
    {
        Node temp(i);
        que.push(temp);
    }

    cout<<que.top()._val<<endl;
    return 0;
}
