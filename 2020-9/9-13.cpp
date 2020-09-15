/*************************************************************************
# File Name: 9-13.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月15日 星期二 11时33分37秒
*************************************************************************/
/*
class Solution {
public:
    bool IsTrue(char ch)
    {
        if(ch >= '0' && ch <= '9')
        {
            return true;
        }
        return false;
    }

    int myAtoi(string str) {
        //判空
        if(str.empty() || str == "")
        {
            return 0;
        }

        int index = 0;

        //处理空格
        while(index < str.size() && str[index] == ' ')
        {
            index++;
        }

        //全都是空格的情况
        if(index == str.size())
        {
            return 0;
        }

        //处理正负号
        int flag = 1;
        if(str[index] == '+')
        {
            index++;
        }
        else if(str[index] == '-') 
        {
            flag = -1;
            index++;
        }
        //第一个不是数字的情况
        else if(IsTrue(str[index]) == false)
        {
            return 0;
        }
        
        //保存结果
        long long ret = 0;
        while(index < str.size())
        {
            //处理数字的情况
            if(IsTrue(str[index]) == true)
            {
                //2147483647
                //处理溢出
                if(ret > INT_MAX)
                {
                    break;
                }

                ret *= 10;
                ret += (str[index] - '0');
            }
            else 
            {
                break;
            }

            index++;
        }

        ret *= flag;
        //处理溢出情况
        if(ret > INT_MAX)
        {
            ret = INT_MAX;
        }
        else if(ret < INT_MIN)
        {
            ret = INT_MIN;
        }
        
        return ret;
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        int prev = 0;
        int cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur] != 0)
            {
                swap(nums[cur],nums[prev]);
                cur++;
                prev++;
            }
            else 
            {
                cur++;
            }
        }
        */

        /*
        vector<int> arr(nums.size(),0);
        int index = 0;
        for(auto& e : nums)
        {
            if(e != 0)
            {
                arr[index++] = e;
            }
        }

        nums = arr;
        */

        int index = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != 0)
            {
                nums[index++] = nums[i];
            }
        }

        for(;index < nums.size();index++)
        {
            nums[index] = 0;
        }
    }
};

#include <iostream>
using namespace std;

class Test 
{
    public:
        int x;
        int y;
        int z;
};

int main()
{
    Test* test = NULL;
    int* offset = (int*)(&(test->z));
    cout<<offset - NULL<<endl;
    return 0;
}
