#include "Header.hpp"

//最长公共序列
int longestCommonSubsequence(string text1, string text2)
{
  vector<vector<int>> dp(text1.size() + 1,vector<int>(text2.size() + 1,0));
  
  //遍历两个字符
  for(size_t i = 1;i <= text1.size();i++)
  {
    for(size_t j = 1;j <= text2.size();j++)
    {
      //如果这两个字符相等，就说明该字符一定在公共序列当中
      if(text1[i - 1] == text2[j - 1])
      {
        dp[i][j] = dp[i -1][j - 1] + 1;
      }
      else //反之：1.text1在 2.text2在 3.都不在
        //只考虑1，2两种情况，选取其中最大的情况即可
      {
        dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
      }
    }
  }
  return dp[text1.size()][text2.size()];
}

int Dp(string text1,string text2,int i,int j)
{
  //如果两个字符的指针有任何一个结束，就直接返回，因为没有字符肯定找不到匹配
  if(i < 0 || j < 0)
  {
    return 0;
  }


  //如果对应位置的字符相等，就直接给计数器++，递归求两个字符串的钱一个位子
  if(text1[i] == text2[j])
  {
    return Dp(text1,text2,i - 1,j - 1) + 1;
  }
  else //反之求两个字符中出现其中一个的情况中是公共序列最长的情况
  {
    return max(Dp(text1,text2,i,j - 1),Dp(text1,text2,i - 1,j));
  }
}

int main()
{
  string text1 = "abcdefghert";
  string text2 = "aceght";
  cout<<longestCommonSubsequence(text1,text2)<<endl;
  cout<<Dp(text1,text2,text1.size() - 1,text2.size() - 1)<<endl;
  return 0;
}
