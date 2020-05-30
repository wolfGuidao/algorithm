/*************************************************************************
  > File Name: 6-11.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月30日 星期六 18时52分11秒
 ************************************************************************/

#include "Header.hpp"

int trap(vector<int>& height) 
{
    int n = height.size();
    int ans = 0;
    
    for (int i = 1; i < n - 1; i++) 
    {
        int l_max = 0, r_max = 0;
        
        // 找右边最高的柱子
        for (int j = i; j < n; j++)
            r_max = max(r_max, height[j]);
        
        // 找左边最高的柱子
        for (int j = i; j >= 0; j--)
            l_max = max(l_max, height[j]);
        
        // 如果自己就是最高的话，
        // l_max == r_max == height[i]
        ans += min(l_max, r_max) - height[i];
    }
    return ans;
}


int trap1(vector<int>& height) 
{
    if (height.empty()) 
    	return 0;
    
    int n = height.size();
    int ans = 0;
    
    // 数组充当备忘录
    vector<int> l_max(n), r_max(n);
    
    // 初始化 base case
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];
    
    // 从左向右计算 l_max
    for (int i = 1; i < n; i++)
        l_max[i] = max(height[i], l_max[i - 1]);
    
    // 从右向左计算 r_max
    for (int i = n - 2; i >= 0; i--) 
        r_max[i] = max(height[i], r_max[i + 1]);
    
    // 计算答案
    for (int i = 1; i < n - 1; i++) 
        ans += min(l_max[i], r_max[i]) - height[i];
    return ans;
}

