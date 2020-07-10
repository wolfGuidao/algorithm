/*************************************************************************
  > File Name: 7-28.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月10日 星期五 11时56分04秒
 ************************************************************************/

#include "Header.hpp"

class A 
{
    public:
        A()
        {}

        A(const int& a)
            :_a(a)
        {}

    private:
        int _a;
};


#if 0
#include<iostream>
using namespace std;
 
double luck(double n)
{
	if(n == 1 || n == 2)
	{
		return n - 1;
	}
	
	return ((n - 1)*(luck(n - 1) + luck(n - 2)));
}
	
int main()
{
	double n;
	while (cin >> n)
	{
		//错排的方案数
		double lu = luck(n);

		//总的方案数
		double all = 1;
		for (double i = 1;i <= n;++i)
		{
			all *= i;
		}
		
		//概率
		lu = lu / all*100;
		
		printf("%.2f%%\n", lu);
	}
	return 0;
}
#endif 

int maxCoins(int[] nums) 
{
    int n = nums.length;
    // 添加两侧的虚拟气球
    int[] points = new int[n + 2];
    points[0] = points[n + 1] = 1;
    for (int i = 1; i <= n; i++) 
    {
        points[i] = nums[i - 1];
    }
    
    // base case 已经都被初始化为 0
    int[][] dp = new int[n + 2][n + 2];
    
    // 开始状态转移
    // i 应该从下往上
    for (int i = n; i >= 0; i--) 
    {
        // j 应该从左往右
        for (int j = i + 1; j < n + 2; j++) 
        {
            // 最后戳破的气球是哪个？
            for (int k = i + 1; k < j; k++) 
            {
                // 择优做选择
                dp[i][j] = Math.max(
                    dp[i][j], 
                    dp[i][k] + dp[k][j] + points[i]*points[j]*points[k]
                );
            }
        }
    }
    return dp[0][n + 1];
}

