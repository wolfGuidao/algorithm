/*************************************************************************
    > File Name: 6-17.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月04日 星期四 16时32分31秒
 ************************************************************************/

#include "Header.hpp"

class Solution {
public:
    int cutRope(int number) {
    	//记录求长度为number前的子长度结果
        vector<int> dp(number + 1);
        
        // number<=3的情况，因为m>1必须要分段，例如：3必须分成1、2；1、1、1 ，
        //number=3最大分段乘积是2,
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;
        
        //下面是number>=4的情况，跟number<=3不同，4可以分很多段，比如分成1、3，
        //这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

		//保存结果
        int ret = INT_MIN;
        //主要思想是每次把绳子分为j份，每次分别求最大的乘积
        //再在过程中记录最大值
       for (int i = 4; i <= number; i++) 
       {
            for (int j = 1; j <= i/2 ; j++) 
            {
            	//更新最大值，这里你只看到分为两端，一段j，另一端为i - j
            	//但是j和i - j在之前的计算中同样经历了这样的计算判断
            	//即j和i - j是分为m段中最大最优的结果
            	//所以i同样就是分为m段中最大最优的结果
                ret = max(ret,dp[j] * dp[i - j]);
            }
            dp[i] = ret;
        }
        return dp[number];
    }
};




int main()
{

    return 0;
}



