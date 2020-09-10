/*************************************************************************
# File Name: 9-9.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月10日 星期四 10时57分42秒
*************************************************************************/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        int index = 1;
        while(1)
        {
            if(my_map[index] == 0)
            {
                return index;
            }
            index++;
        }

        return 0;
        */

        int n = nums.size();
        for(int i = 0;i < nums.size();i++)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i],nums[nums[i] - 1]);
            }
        }

        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};
