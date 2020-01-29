#include "Header.hpp"

//最长回文子序列
int longestPalindromeSubseq(string s) 
{
  vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));

  //data base:
  //当i和j相等时就代表i和j之间只有一个字符，说明回文长度为1
  for(int i = 0;i < s.size();i++)
  {
    dp[i][i] = 1;
  }


  //反向遍历
  //dp[i][j]:代表在i,j区间内的回文序列的长度
  for(int i = s.size() - 1;i >= 0;i--)
  {
    for(int j = i + 1;j < s.size();j++)
    {
      //如果对应字符相等，就直接直接+2
      if(s[i] == s[j])
      {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      }
      else //反之对应位置的字符可能有一个出现在回文串当中，取决于谁能使回文串更长
      {
        dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
      }
    }
  }
  return dp[0][s.size() - 1];
}

class Solution {
  public:
    int longestPalindromeSubseq(string s) {
      vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));

      //根据base case的定义：当只剩下一个字符的时候，直接return 1，因为字符本身和自己肯定是满足回文
      //关系的，有根据dp数组的定义，dp[i][j]代表在[1...j]区间内最长的回文子序列的长度，什么情况下只
      //剩下一个字符呢，当i == j的时候，不就代表只剩下一个字符了，在DP table中，直接把相应位置置为1即可
      for(int i = 0;i < s.size();i++)
      {
        dp[i][i] = 1;
      }

      //只能反向或者斜向遍历，详情请看博客
      for(int i = s.size() - 1;i >= 0;i--)
      {
        for(int j = i + 1;j < s.size();j++)
        {
          if(s[i] == s[j])//如果当前两个字符相等，就把dp[i + 1][j - 1]当最长回文子序列当长度 + 2即可
          {
            dp[i][j] = dp[i + 1][j - 1] + 2;
          }
          else//反之，1.i位处当元素在最长回文子序列当中；2.j位处当元素在最长回文子序列当中；
            //3.都不在最长回文子序列当中；主要是1，2两种情况，第3种情况的最长回文子序列长度只会比1，2两种情况小，
            //取1，2两种情况中最大的返回即可
          {
            dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
          }
        }
      }

      //根据博客当中的图，最后的结果并不在[max][max]或者[0][0]，而是在[0][max]当中
      return dp[0][s.size() - 1];
    }
};

int main()
{
  string s = "bbbab";
  cout<<longestPalindromeSubseq(s)<<endl;
  Solution lo;
  cout<<lo.longestPalindromeSubseq(s)<<endl; 
  return 0;
}
