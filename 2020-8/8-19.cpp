/*************************************************************************
# File Name: 8-19.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月20日 星期四 16时40分31秒
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 计算字符串形式的整数的差
     * @param num1 string字符串 被减数（字符串形式）
     * @param num2 string字符串 减数（字符串形式）
     * @return string字符串
     */
    string sub_strings(string num1, string num2) {
        // write code here
        if(num1.empty() || num2.empty())
        {
            return "";
        }
        
        string ret = "";
        int index_num1 = num1.size() - 1;
        int index_num2 = num2.size() - 1;
        int money = 0;
        while(index_num1 >= 0 && index_num2 >= 0)
        {
            int val1 = num1[index_num1] - '0' + money;
            int val2 = num2[index_num2] - '0';
            
            if(val1 < val2)
            {
                money = -1;
                val1 += 10;
                int res = val1 - val2;
                ret += to_string(res);
            }
            else 
            {
                money = 0;
                int res = val1 - val2;
                ret += to_string(res);
            }
            index_num1--;
            index_num2--;
        }
        
        while(index_num1 >= 0)
        {
            if(money == -1)
            {
                int res = num1[index_num1] - '0' + money;
                if(res < 0)
                {
                    money == -1;
                    ret += to_string(9);
                    
                }
                else 
                {
                    ret += to_string(res);
                    money = 0;
                }
                index_num1--;
            }
            else 
            {
                ret += num1[index_num1--];
            }
            
        }
        
        reverse(ret.begin(),ret.end());
        
        int index = 0;
        while(ret[index] == '0')
        {
            index++; 
        }
        
        return ret.substr(index,ret.size() - index);
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        //我们可以把问题转化成数组中的所有数到某一点的距离之和最小
        //num[0] - val + num[1] - val +...+ num[n] - val
        //这个数就是数组的中位数
        sort(nums.begin(),nums.end());
        int val = nums[nums.size() / 2];

        int ret = 0;
        for(auto& e : nums)
        {
            ret += abs(e - val);
        }

        return ret;
    }
};

int main()
{
    string str1 = "123456789123456789123456789";
    string str2 = "789";
    cout<<str1<<" - "<<str2<<" : "<<endl;
    cout<<Solution().sub_strings(str1,str2)<<endl;
    return 0;
}
