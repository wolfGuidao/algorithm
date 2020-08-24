/*************************************************************************
# File Name: 8-22.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月24日 星期一 21时53分48秒
*************************************************************************/
class Solution {
public:
    vector<vector<int>> ret;

    bool IsEque(vector<int>& a,vector<int>& b)
    {
        if(a.size() != b.size())
        {
            return true;
        }

        for(int i = 0;i < a.size();i++)
        {
            if(a[i] != b[i])
            {
                return true;
            }
        }
        return false;
    }

    bool IsTrue(vector<int>& track)
    {
        for(auto& e : ret)
        {
            if(!IsEque(e,track))
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<int>& nums,vector<int>& track,int index)
    {
        if(IsTrue(track))
        {
            ret.push_back(track);
        }

        for(int i = index;i < nums.size();i++)
        {
            track.push_back(nums[i]);
            backtrack(nums,track,i + 1);
            track.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }

        sort(nums.begin(),nums.end());
        vector<int> track;
        backtrack(nums,track,0);
        return ret;
    }
};
