#include "Header.hpp"

//编辑距离
#if 0
int Min(int a,int b,int c)
{
  return min(a,min(b,c));
}

int dp(string word1,string word2,int w1,int w2)
{
  if(w1 < 0)
  {
    return w2 + 1;
  }

  if(w2 < 0)
  {
    return w1 + 1;
  }

  if(word1[w1] == word2[w2])
  {
    return dp(word1,word2,w1 - 1,w2 - 1);
  }
  else 
  {
    return Min(dp(word1,word2,w1 - 1,w2 - 1) + 1,dp(word1,word2,w1 - 1,w2) + 1,dp(word1,word2,w1,w2 - 1) + 1) ;
  }
}
#endif

enum choice 
{
  Not,
  Add,
  Down,
  Replace 
};

#if 1
class Node
{
  public:
    Node()
      :val(0)
       ,ch(Not)
  {

  }

    int val;
    choice ch;
};

class Solution 
{
  public:
    int Min(int a, int b, int c)
    {
      return min(a, min(b, c));
    }

    int minDistance(string word1, string word2) 
    {
      int m = word1.size();
      int n = word2.size();

      vector<vector<Node>> dp(word1.size() + 1,vector<Node>(word2.size() + 1,Node()));

      for (int i = 1; i <= m; i++)
      {
        dp[i][0].val = i;
        cout<<"本次操作是：删除"<<endl;
      }

      for (int j = 1; j <= n; j++)
      {
        dp[0][j].val = j;
        cout<<"本次操作是：插入"<<endl;
      }

      for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)

          if (word1[i-1] == word2[j-1])
          {
            dp[i][j].val = dp[i - 1][j - 1].val;
            cout<<"本次操作是：什么都不干"<<endl;
          }
          else //返回三种操作所需要的最少操作次数，原理和动态规划当原理一样
          {
            dp[i][j].val = Min(
                dp[i - 1][j].val + 1,
                dp[i][j - 1].val + 1,
                dp[i-1][j-1].val + 1
                );
            if(dp[i][j].val - 1 == dp[i - 1][j].val)
            {
              cout<<"本次操作是：删除"<<endl;
            }
            if(dp[i][j].val - 1 == dp[i][j - 1].val)
            {
              cout<<"本次操作是：插入"<<endl;
            }
            if(dp[i][j].val - 1 == dp[i - 1][j - 1].val)
            {
              cout<<"本次操作是：替换"<<endl;
            }
          }
      return dp[m][n].val;
    }
};
#endif

#if 0
class Solution {
  public:
    int Min(int a, int b, int c)
    {
      return min(a, min(b, c));

    }
    int minDistance(string word1, string word2) {
      int m = word1.size();
      int n = word2.size();

      vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));


      // base case,根据博客中的DP table 那张图，dp[i][0]] = i 或者 dp[0][j] = j 代表当两个字符串其中一个为空时，直接返回对应当长度（还是那句话，当其中一个字符串为空 或 者其中一个字符串先一步遍历结束时，直接返回对方字符串剩下长度，因为此时要么是删除，要么是插入，都会增加相应的次数）
      for (int i = 1; i <= m; i++)
        dp[i][0] = i;

      for (int j = 1; j <= n; j++)
        dp[0][j] = j;

      // ⾃ 底向上求解，开始遍历
      for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {

          //注意下标，i和j是从1开始当，而字符串是从0开始当
          //如果对应字符s1.[i-1] == s2.[j-1]相等时，没有增加次数，直接等于dp[i - 1][j - 1]
          if (word1[i-1] == word2[j-1])
            dp[i][j] = dp[i - 1][j - 1];
          else //返回三种操作所需要的最少操作次数，原理和动态规划当原理一样
            dp[i][j] = Min(
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i-1][j-1] + 1
                );
        }
          // dp储存着整个 s1 和 s2 的最⼩编辑距离
      return dp[m - 1][n - 1];
    }

};
#endif

int main()
{
  string word1 = "horse";
  string word2 = "ros";
  Solution s;
  cout<<s.minDistance(word1,word2)<<endl;
  return 0;
}
