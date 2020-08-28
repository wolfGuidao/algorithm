/*************************************************************************
# File Name: 8-26.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月28日 星期五 13时31分53秒
*************************************************************************/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        /*
        int ret = 0;
        int index = 0;
        while(index < nums.size())
        {
            if(index == 0 && index + 1 < nums.size() && nums[index] > nums[index + 1])
            {
                ret = index;
                break;
            }

            if(index - 1 >= 0 && index + 1 < nums.size())
            {
                if(nums[index - 1] < nums[index] && nums[index] > nums[index + 1])
                {
                    ret = index;
                    break;
                }
            }

            if(index == nums.size() - 1 && index - 1 >= 0 && nums[index] > nums[index - 1])
            {
                ret = index;
                break;
            }

            index++;
        }
        return ret;
        */

        int l = 0, r = nums.size() - 1;
        while (l < r) 
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;

    }
};
