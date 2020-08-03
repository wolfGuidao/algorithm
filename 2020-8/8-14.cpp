/*************************************************************************
# File Name: 8-14.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月31日 星期五 09时50分59秒
*************************************************************************/
#include <iostream>
#include <stack>
using namespace  std;

#if 0
int main()
{
    stack<int> s1;
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    stack<int> s2;
    int temp1 = s1.top();
    s1.pop();
    int temp2 = s2.top();
    s2.pop();

    while(!s1.empty())
    {
        if(temp1 >= temp2)
        {
            s2.push(temp1);
            if(!s1.empty())
            {
                temp1 = s1.top();
                s1.pop();
            }
        }
        else 
        {
            s2.push(temp2);
            if(!s1.empty())
            {
                temp2 = s1.top();
                s1.pop();
            }
        }
    }

    temp1 = s2.top();
    s2.pop();
    temp2 = s2.top();
    s2.pop();

    while(!s2.empty())
    {
        if(temp1 >= temp2)    
        {    
            s1.push(temp2);    
            if(!s2.empty())    
            {    
                temp2 = s2.top();    
                s2.pop();    
            }    
        }    
        else     
        {    
            s1.push(temp1);    
            if(!s2.empty())    
            {    
                temp1 = s2.top();    
                s2.pop();    
            }    
        }    

    }

    while(!s1.empty())
    {
        cout<<s1.top()<<" : ";
    }
    cout<<endl;
    return 0;
}
#endif

int main()
{
    return 0;
}

class Solution {
public:
    int GetSum(int index_x,int index_y)
    {
        int sum = 0;
        while(index_x)
        {
            int temp = index_x % 10;
            index_x = index_x / 10;
            sum += temp;
        }

        while(index_y)
        {
            int temp = index_y % 10;
            index_y = index_y / 10;
            sum += temp;
        }

        return sum;
    }

    int count = 0;

    void help(int m,int n,int k,int x,int y,vector<vector<int>>& visted)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || GetSum(x,y) > k || visted[x][y])
        {
            return ;
        }

        visted[x][y] = 1;
        count++;
        help(m,n,k,x + 1,y,visted);
        help(m,n,k,x - 1,y,visted);
        help(m,n,k,x,y + 1,visted);
        help(m,n,k,x,y - 1,visted);
    }

    int movingCount(int m, int n, int k) {
        if(m == 0 && n == 0)
        {
            return 0;
        }

        vector<vector<int>> visted(m,vector<int>(n,0));

        help(m,n,k,0,0,visted);

        return count;
    }
};
