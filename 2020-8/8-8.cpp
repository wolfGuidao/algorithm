/*************************************************************************
# File Name: 8-8.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月22日 星期三 23时52分59秒
*************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int SumStr(string str)
    {
        int sum = 0;
        for(int i = 1;i <= str.size();i++)
        {
            sum += i;
        }
        return sum;
    }
    int numSub(string s) {
        int sum = 0;
        cout<<s<<endl;
        string str = "";
        for(auto e : s)
        {
            if(e == '1')
            {
                str += e;
            }
            else 
            {
                cout<<s<<endl;
                int temp = SumStr(str);
                sum += temp;

                temp = 0;
                str = "";
            }
        }
        if(!str.empty())
        {
            sum += SumStr(str);
        }
        return sum;
    }
};

int main()
{
    cout<<Solution().numSub("111")<<endl;;
    return 0;
}
