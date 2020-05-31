/*************************************************************************
  > File Name: 6-14.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月31日 星期日 16时47分57秒
 ************************************************************************/

#include "Header.hpp"

class Solution {
  public:
    // 时间复杂度 O(N)
    bool canFinish(vector<int> piles, int speed, int H) 
    {
      int time = 0;
      for (int n : piles) 
      {
        time += timeOf(n, speed);
      }
      return time <= H;
    }

    int timeOf(int n, int speed) 
    {
      return (n / speed) + ((n % speed > 0) ? 1 : 0);
    }

    int getMax(vector<int> piles) 
    {
      int maxx = 0;
      for (int n : piles)
        maxx = std::max(n, maxx);
      return maxx;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
      // 套用搜索左侧边界的算法框架
      int left = 1, right = getMax(piles) + 1;
      while (left < right) 
      {
        // 防止溢出
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, H)) 
        {
          right = mid;
        } 
        else 
        {
          left = mid + 1;
        }
      }
      return left;
    }
};

class Solution {
  public:
    int getMax(vector<int> piles) 
    {
      int maxx = 0;
      for (int n : piles)
        maxx = std::max(n, maxx);
      return maxx;
    }
    int getSum(vector<int> piles) 
    {
      int sum = 0;
      for (int n : piles)
        sum += n;
      return sum;
    }
    // 寻找左侧边界的二分查找
    int shipWithinDays(vector<int> weights, int D) 
    {
      // 载重可能的最小值
      int left = getMax(weights);

      // 载重可能的最大值 + 1
      int right = getSum(weights) + 1;
      while (left < right) 
      {
        int mid = left + (right - left) / 2;
        if (canFinish(weights, D, mid)) 
        {
          right = mid;
        } 
        else 
        {
          left = mid + 1;
        }
      }
      return left;
    }

    // 如果载重为 cap，是否能在 D 天内运完货物？
    bool canFinish(vector<int> w, int D, int cap) 
    {
      int i = 0;
      for (int day = 0; day < D; day++) 
      {
        int maxCap = cap;
        while ((maxCap -= w[i]) >= 0) 
        {
          i++;
          if (i == w.size())
            return true;
        }
      }
      return false;
    }

};

int main()
{

  return 0;
}

