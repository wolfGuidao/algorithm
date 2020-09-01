/*************************************************************************
# File Name: 8-28.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月01日 星期二 22时10分19秒
*************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> GetNext(string& match)
{
    vector<int> next(match.size() + 1,0);
    next[0] = -1;
    
    int i = 2;
    int k = 0;
    while(i < match.size())
    {
        if(match[i - 1] == match[k])
        {
            next[i] = k + 1;
            k = next[i];
            i++;
        }
        else if(k == 0)
        {
            next[i] = 0;
            i++;
        }
        else 
        {
            k = next[k];
        }
    }
    return next;
}

int main()
{
    string str;
    string match;
    while(getline(cin,str))
    {
        getline(cin,match);
        vector<int> next = GetNext(match);
        
        int flag = 1;
        
        int i = 0;
        int j = 0;
        while(i < str.size())
        {
            if(str[i] == match[j])
            {
                i++;
                j++;
                if(j == match.size())
                {
                    flag = 0;
                    cout<<i - match.size()<<" ";
                    j = next[j];
                }
            }
            else
            {
                j = next[j];
                if(j == -1)
                {
                    j = 0;
                    i++;
                }
            }
        }
        if(flag)
            cout<<-1<<endl;
    }
    return 0;
}
