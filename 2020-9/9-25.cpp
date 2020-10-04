/*************************************************************************
# File Name: 9-25.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年10月04日 星期日 19时34分12秒
*************************************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        vector<int> left(nums.size(),1);

        vector<int> right(nums.size(),1);

        vector<int> ret(nums.size(),0);

        for(int i = 1;i < nums.size();i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for(int i = nums.size() - 2;i >= 0;i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0;i < nums.size();i++)
        {
            ret[i] = left[i] * right[i];
        }

        return ret;
        */

        vector<int> ret(nums.size(),1);
        for(int i = 1;i < nums.size();i++)
        {
            ret[i] = ret[i - 1] * nums[i - 1];
        }

        int right = 1;
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            ret[i] = ret[i] * right;
            right *= nums[i];
        }

        return ret;
    }
};
