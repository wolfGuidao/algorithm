#include "Header.hpp"


class Solution {
public:

    int dp(vector<int>& coins, int rem, vector<int> &count)
    {
        if (rem < 0) 
            return -1;

        if (rem == 0) 
            return 0;

        // ！= 0 代表count[rem - 1]已经计算过且保存在count中，直接返回，不用重复计算
        if (count[rem - 1] != 0)
             return count[rem - 1];

        int min = INT_MAX;
        for (int coin : coins) 
        {
            int res = dp(coins, rem - coin, count);

            if (res >= 0 && res < min)
                min = 1 + res;
        }

        //保存结果，为下一次的计算减轻负担
        count[rem - 1] = (min == INT_MAX) ? -1 : min;
        return count[rem - 1];

    }
    

    int coinChange(vector<int>& coins, int amount) {
    
    if (amount < 1) 
        return 0;

    vector<int> count(amount);//传递一个数组用来记录计算过到值，避免重复计算
        return dp(coins, amount, count);
    }
};

int main()
{
  vector<int> arr{1, 2, 5};
  cout<<Solution().coinChange(arr, 11)<<endl;
  return 0;
}

