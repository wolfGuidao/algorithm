/*************************************************************************
  > File Name: 7-20.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月03日 星期五 16时07分24秒
 ************************************************************************/

#include "Header.hpp"
#include <limits.h>

#if 0
vector<vector<int>> ret;

bool IsIn(vector<int> arr,int num)
{
    for(auto e : arr)
    {
        if(e == num)
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<int>& arr,int start,vector<int>& track)
{
    ret.push_back(track);

    for(int i = start;i < arr.size();i++)
    {
        track.push_back(arr[i]);
        backtrack(arr,i + 1,track);
        track.pop_back();
    }
}


//void backtrack(vector<int>& nums, int start, vector<int>& track) {
//    ret.push_back(track);
//    for (int i = start; i < nums.size(); i++) {
//        // 做选择
//        track.push_back(nums[i]);
//        // 回溯
//        backtrack(nums, i + 1, track);
//        // 撤销选择
//        track.pop_back();
//    }
//}

int main()
{
    vector<int> arr{1,2,3};
    vector<int> track;

    backtrack(arr,0,track);

    int count = 0;
    for(auto e : ret)
    {
        cout<<"[";
        int sum = 0;
        for(auto m : e)
        {
            count++;
            cout<<m<<" ";
            sum += m;
        }
        cout<<"]"<<"sum = : "<<sum<<endl;
    }
    cout<<"count: "<<count<<endl;
    return 0;
}


#endif


class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    
    vector<vector<int>> ret;
    void backtrack(vector<int> arr,int start,vector<int> track)
    {
        ret.push_back(track);
        
        for(size_t i = start;i < arr.size();i++)
        {
            track.push_back(arr[i]);
            backtrack(arr,i + 1,track);
            track.pop_back();
        }
    }
    
	int getFirstUnFormedNum(vector<int> arr, int len) {
        int min_left = INT_MAX;
        int max_right = 0;
        
        for(size_t i = 0;i < arr.size();i++)
        {
            if(arr[i] < min_left)
            {
                min_left = arr[i];
            }
            
            max_right += arr[i];
        }
        
        vector<int> track;
        backtrack(arr,0,track);
        
        unordered_map<int,int> unorder;
        for(size_t i = 0;i < ret.size();i++)
        {
            int sum = 0;
            int flag = true;
            for(auto e : ret[i])
            {
                sum += e;
                flag = false;
            }
            if(flag)
                continue;
            unorder[sum]++;
        }
        
        for(int begin = min_left;begin <= max_right;begin++)
        {
            if(unorder.count(begin) == 0)
            {
                return begin;
            }
        }
        return max_right + 1;
        
    
    //int getFirstUnFormedNum(vector<int> arr, int len) {
    }
};

int main()
{
    //vector<int> arr{3,2,5};
    //vector<int> arr{3,2,4};
    vector<int> arr{1,2,3,4};
    cout<<Solution().getFirstUnFormedNum(arr,arr.size())<<endl;
    return 0;
}
