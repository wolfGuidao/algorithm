/*************************************************************************
# File Name: 8-25.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月27日 星期四 18时33分13秒
*************************************************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return false;
        }

        /*
        unordered_map<int,int> my_map;
        for(int i = 0;i < nums.size();i++)
        {
            if(my_map.count(nums[i]) >= 1)
            {
                return true;
            }

            my_map[nums[i]]++;

            if(my_map.size() > k)
            {
                my_map.erase(nums[i - k]);
            }
        }

        return false;
        */
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty())
        {
            return false;
        }

        for(int i = 0;i < nums.size();i++)
        {
            for(int j = max(i - k,0);j < i;j++)
            {
                if(abs((static_cast<long>(nums[i])) - (static_cast<long>(nums[j]))) <= t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
