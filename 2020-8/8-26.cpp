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

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        int i = 0;
        int j = 0;
        while(i < n1 || j < n2)
        {
            int index1 = i;
            int index2 = j;
            while(index1 < n1 && version1[index1] != '.')
            {
                index1++;
            }

            while(index2 < n2 && version2[index2] != '.')
            {
                index2++;
            }

            int num1 = (index1 == i ? 0 : stoi(version1.substr(i,index1 - i)));
            int num2 = (index2 == j ? 0 : stoi(version2.substr(j,index2 - j)));
            if(num1 > num2)
            {
                return 1;
            }
            else if(num1 < num2)
            {
                return -1;
            }
            i = index1 + 1;
            j = index2 + 1;
        }

        return 0;
    }
};


