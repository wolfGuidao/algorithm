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

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> num(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>num[i];
    }

    int K;
    int D;
    cin>>K>>D;

    vector<vector<long>> dpm(K + 1,vector<long>(n + 1));//dpm[i][j]表示选中了i个人，以第j个人结尾的能力最大乘积
    vector<vector<long>> dpn(K + 1,vector<long>(n + 1));;//dpn[i][j]表示选中了i个人，以第j个人结尾的能力最小乘积

    for(int j = 1; j < n + 1; j++)
    {//初始
        dpm[1][j] = num[j];
        dpn[1][j] = num[j];
    }

    for(int i = 1; i < K + 1; i++)
    {//初始
        dpm[i][1] = num[1];
        dpn[i][1] = num[1];
    }

    for(int i = 2;i < K + 1;i++)
    {
        for(int j = 2;j < n + 1;j++)
        {
            for(int k = max(1,j - D);k < j;k++)
            {
                dpm[i][j] = max(dpm[i][j],max(dpm[i - 1][k] * num[j],dpn[i - 1][k] * num[j]));
                dpn[i][j] = min(dpn[i][j],min(dpm[i - 1][k] * num[j],dpn[i - 1][k] * num[j]));
            }
        }
    }
    long max_num = max(dpm[K][1],dpn[K][1]);
    for(int j = 2;j < n + 1;j++)
    {
        max_num = max(max(dpm[K][j],dpn[K][j]),max_num);
    }
    cout<<max_num<<endl;
    return 0;
}
