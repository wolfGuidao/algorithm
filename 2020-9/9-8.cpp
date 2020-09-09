/*************************************************************************
# File Name: 9-8.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月09日 星期三 10时28分05秒
*************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> sta;

        vector<int> count(256,0);

        for(auto& e : text)
        {
            count[e - '0']++;
        }

        vector<bool> instack(256,false);

        for(auto& e : text)
        {
            count[e - '0']--;
            if(instack[e - '0'] == true)
            {
                continue;
            }

            while(!sta.empty() && sta.top() > e)
            {
                if(count[sta.top() - '0'] == 0)
                {
                    break;
                }

                instack[sta.top() - '0'] = false;
                sta.pop();
            }
            sta.push(e);
            instack[e - '0'] = true;
        }

        string ret;
        while(!sta.empty())
        {
            ret += sta.top();
            sta.pop();
        }

        reverse(ret.begin(),ret.end());

        return ret;
    }
    };

int main()
{
    int a = 999;
    void* ptr = &a;
    void* test = (void*)malloc(256);

    return 0;
}
