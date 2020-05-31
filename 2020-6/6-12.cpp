/*************************************************************************
  > File Name: 6-12.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月31日 星期日 15时44分01秒
 ************************************************************************/

#include "Header.hpp"

bool canJump(vector<int>& nums) 
{
    int n = nums.size();
    int farthest = 0;
    
    for (int i = 0; i < n - 1; i++) 
    {
        // 不断计算能跳到的最远距离
        farthest = max(farthest, i + nums[i]);
        // 可能碰到了 0，卡住跳不动了
        if (farthest <= i) 
        	return false;
    }
    return farthest >= n - 1;
}

vector<int> memo;
// 主函数
int jump(vector<int>& nums) 
{
    int n = nums.size();
    // 备忘录都初始化为 n，相当于 INT_MAX
    // 因为从 0 调到 n - 1 最多 n - 1 步
    memo = vector<int>(n, n);
    return dp(nums, 0);
}

int dp(vector<int>& nums, int p) 
{
    int n = nums.size();
    
    // base case
    if (p >= n - 1) 
    {
        return 0;
    }
    
    // 子问题已经计算过
    if (memo[p] != n) 
    {
        return memo[p];
    }
    
    int steps = nums[p];
    
    // 你可以选择跳 1 步，2 步...
    for (int i = 1; i <= steps; i++) 
    {
        // 穷举每一个选择
        // 计算每一个子问题的结果
        int subProblem = dp(nums, p + i);
        // 取其中最小的作为最终结果
        memo[p] = min(memo[p], subProblem + 1);
    }
    return memo[p];
}

int jump(vector<int>& nums) 
{
    int n = nums.size();
    int end = 0, farthest = 0;
    
    int jumps = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        farthest = max(nums[i] + i, farthest);
        if (end == i) 
        {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}


int main()
{

  return 0;
}

