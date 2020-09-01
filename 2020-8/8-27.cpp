/*************************************************************************
# File Name: 8-27.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月31日 星期一 20时58分52秒
*************************************************************************/
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * 翻译组合数
     * @param num int整型 数字加密报文
     * @return int整型
     */
    
    int dp(string& str,int index)
    {
        cout<<str<<endl;
        if(index == str.size())
        {
            return 1;
        }
        else if(index > str.size())
        {
            return 0;
        }
        
        int ret = 0;
        if(index - 1 >= 0)
        {
            cout<<"2"<<endl;
            int temp = (str[index - 1] * 10) + (str[index] - '0');
            if(temp < 26 && temp >= 0)
            {
                ret += dp(str,index + 1);
            }
            else 
            {
                ret += 0;
            }
        }
        cout<<1<<endl;
        ret += dp(str,index + 1);
        return ret;
    }
    
    int translateNum(int num) {
        // write code here
        if(num < 0)
        {
            return 0;
        }
        
        string str = to_string(num);
        return dp(str,0);
    }
};


int main()
{
    cout<<Solution().translateNum(12158)<<endl;
    return 0;
}
