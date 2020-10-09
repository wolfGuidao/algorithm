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
