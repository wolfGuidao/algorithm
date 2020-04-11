#include "Header.hpp"

class Solution {
  public:
    // 动态规划
    bool isMatch(string s, string p) {
      int ns = s.size();
      int np = p.size();

      if(p.empty()) //注意这里判断的写法，不能是if(p.empty() || s.empty());原因试一下就知道啦
        return s.empty();

      vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));

      //就是博客中的问题，怎么判断前面是否匹配，相当于提前把遇到‘*’的情况在dp[i][j - 2]
      //的情况先记录下来，后面使用，因为初始化的时候全部都是false，所以要提前处理
      dp[0][0] = true;
      for(int i = 1; i <= np; i++)
      {
        if(i-2 >= 0 && p[i-1] == '*' && p[i-2])
        {
          dp[0][i] = dp[0][i-2];
        }
      }

      for(int i = 1; i <= ns; i++)
      {
        for(int j = 1; j <= np; j++)
        {
          if(p[j-1] == s[i-1] || p[j-1] == '.')
            dp[i][j] = dp[i-1][j-1];//万金油，直接相等

          if(p[j-1] == '*')
          {
            bool zero, one;
            if(j-2 >= 0)
            {
              zero = dp[i][j-2];//匹配0次，
              one = (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];//匹配1次
              dp[i][j] = zero || one;//有一个为真即可
            }
          }
        }
      }
      return dp[ns][np];
    }


};

