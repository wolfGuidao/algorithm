#include <string>
#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
  int n = s.size();
  // dp 数组全部初始化为 0
  vector<vector<int>> dp(n, vector<int>(n, 0));
  // base case
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;
  // 反着遍历保证正确的状态转移
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      // 状态转移⽅程
      if (s[i] == s[j])
        dp[i][j] = dp[i + 1][j - 1] + 2;
      else
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }
  } 
  // 整个 s 的最⻓回⽂⼦串⻓度
  return dp[0][n - 1];
}
