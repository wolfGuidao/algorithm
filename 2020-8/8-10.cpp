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

/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
        {
            return 0;
        }

        if(divisor == 1)
        {
            return dividend;
        }

        if(divisor == -1)
        {
            if(dividend == INT_MIN)
            {
                return INT_MAX;
            }
            return -dividend;
        }

        int flag = 1;

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            flag = 0;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long ret = div(dividend,divisor);

        if(flag)
        {
            return ret > INT_MAX ? INT_MAX : ret;
        }
        else 
        {
            return -ret;
        }
    }

    long long div(int a,int b)
    {
        if(a < b)
        {
            return 0;
        }

        long long count = 1;
        long long temp_b = b;

        while(a >= (temp_b + temp_b))
        {
            temp_b = temp_b + temp_b;
            count = count + count;
        }

        return count + div(a - temp_b,b);
    }
};
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) 
            return 0;
        
        if(divisor == 1) 
            return dividend;
        
        if(divisor == -1)
        {
            if(dividend > INT_MIN) 
                return -dividend;
            return INT_MAX;
        }

        long a = dividend;
        long b = divisor;
        int sign = 1; 
        if((a > 0 && b < 0) || (a < 0 && b > 0))
        {
            sign = -1;
        }

        a = abs(a);
        b = abs(b);

        long res = div(a,b);

        if(sign > 0)
            return res > INT_MAX ? INT_MAX : res;
        return -res;
    }
    int div(long a, long b)
    {  
        if(a < b) 
            return 0;
        
        long count = 1;
        long tb = b; 
        while((tb + tb) <= a)
        {
            count = count + count;
            tb = tb + tb;
        }
        return count + div(a-tb,b);
    }
};


