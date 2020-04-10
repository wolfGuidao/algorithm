#include "Header.hpp"

//前缀和

int subarraySum(int[] nums, int k) {
  int n = nums.length;
  // 构造前缀和
  int[] sum = new int[n + 1];
  sum[0] = 0; 
  for (int i = 0; i < n; i++)
    sum[i + 1] = sum[i] + nums[i];

  int ans = 0;
  // 穷举所有子数组
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
      // sum of nums[j..i-1]
      if (sum[i] - sum[j] == k)
        ans++;

  return ans;

}

int main()
{
  cout<<"adjvalf"<<endl;
  return 0;
}
