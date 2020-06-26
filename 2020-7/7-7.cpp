/*************************************************************************
    > File Name: 7-7.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月26日 星期五 18时31分50秒
 ************************************************************************/

#include "Header.hpp"

class Solution {
public:
    int dp(int k,int n,vector<vector<int>>& ret)
    {
        //当 k==1 只剩下一个鸡蛋的时候，我们就只能线性测试，即一层一层的测试，所以最坏情况下就是到达n层楼的顶部
        if(k == 1)
        {
            return n;
        }

        //当 n == 0 时，代表已经不用测试了，相当于你在地面测试，没有楼，搞个屁，直接return
        if(n == 0)
        {
            return 0;
        }

        //如果在备忘录中，直接返回，减去重复计算
        if(ret[k][n] != -2)
        {
            return ret[k][n];
        }

        int res = INT_MAX;

        int low = 1;
        int hight = n + 1;

        while(low < hight)
        {
            int mid = (low + hight) >> 1;

            int broken = dp(k - 1,mid - 1,ret);//碎
            int not_brokeb = dp(k,n - mid,ret);//没碎

            //选择碎或者没碎中最差的情况
            if(broken > not_brokeb)
            {
                hight = mid;//更新在鸡蛋碎的时候，相当于在mid的左边进行
                res = min(res,broken + 1);
            }
            else
            {
                //在鸡蛋没碎的时候，相当于在mid的右边进行，和dp函数的原理类似
                low = mid + 1;
                res = min(res,not_brokeb + 1);
            }

        }

        ret[k][n] = res;

        return ret[k][n];
    }
    int superEggDrop(int K, int N) {
        vector<vector<int>> ret(K + 1, vector<int>(N + 1, -2));

        return dp(K,N,ret);
    }
};


int main()
{

    return 0;
}

