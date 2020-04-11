#include "Header.hpp"

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> ret;
      if(intervals.empty())
      {
        return ret;

      }

      //先对intervals的每个区间按第一个元素（start）进行生序排序
      sort(intervals.begin(),intervals.end(),
          [](vector<int> &v1, vector<int> &v2) 
          { 
             return v1[0] < v2[0];
          });

      //遍历整个数组
      for (int i = 0; i < intervals.size(); ++i) 
      {
        //定义一个临时变量，用来记录重叠区间的右边界
        vector<int> temp = intervals[i];

        //代表当前区间和intervals中的下一个区间重叠
        //规定区间[start,end]
        //temp[1] >= intervals[i+1][0]代表当前区间的end位置大于等于下一个区间的start位置
        //如果出现第一个区间的end大于第二个区间的end，可以直接忽略，没起到任何作用
        while (i + 1 < intervals.size() && temp[1] >= intervals[i+1][0]) 
        {
          //继续遍历，因为此时的右边界不一定是最优的，可能还有重叠区间
          ++i;
          //更新区间的右边界
          temp[1] = max(temp[1], intervals[i][1]);
        }
        //记录结果
        ret.push_back(temp);
      }
      return ret;
    }
};

