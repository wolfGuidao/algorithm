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
    cout<<'t' - 'a'<<endl;
    return 0;
}
