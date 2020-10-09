/*************************************************************************
# File Name: 9-27.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年10月09日 星期五 18时48分15秒
*************************************************************************/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }

        vector<string> ret;
        
        int begin = 0;
        int end = 0;

        int index = 1;
        string temp = "";
        while(index < nums.size())
        {
            if(nums[index] == nums[end] + 1)
            {
                end++;
                index++;
            }
            else 
            {
                if(begin == end)
                {
                    temp += to_string(nums[begin]);
                }
                else 
                {
                    temp += to_string(nums[begin]);
                    temp += "->";
                    temp += to_string(nums[end]);
                }
                begin = index;
                end = index;

                ret.emplace_back(temp);
                temp.clear();

                index++;
            }
        }

        if(begin == end)
        {
            temp += to_string(nums[begin]);
        }
        else 
        {
            temp += to_string(nums[begin]);
            temp += "->";
            temp += to_string(nums[end]);
        }

        ret.emplace_back(temp);

        return ret;
    }
};


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        unordered_map<int,int> my_map;
        vector<int> ret;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        for(auto& e : my_map)
        {
            if(e.second > nums.size() / 3)
            {
                ret.emplace_back(e.first);
            }
        }

        return ret;
        */
        if(nums.empty())
        {
            return {};
        }

        int target1 = nums[0];
        int count1 = 0;

        int target2 = nums[0];
        int count2 = 0;

        for(auto& e : nums)
        {
            if(e == target1)
            {
                count1++;
                continue;
            }
            else if(e == target2)
            {
                count2++;
                continue;
            }

            if(count1 == 0)
            {
                target1 = e;
                count1++;
                continue;
            }
            else if(count2 == 0)
            {
                target2 = e;
                count2++;
                continue;
            }

            count1--;
            count2--;
        }

        int val1 = 0;
        int val2 = 0;
        for(auto& e : nums)
        {
            if(e == target1)
            {
                val1++;
            }
            else if(e == target2)
            {
                val2++;
            }
        }

        vector<int> ret;
        if(val1 > nums.size() / 3)
        {
            ret.emplace_back(target1);
        }

        if(val2 > nums.size() / 3)
        {
            ret.emplace_back(target2);
        }

        return ret;
    }
};

