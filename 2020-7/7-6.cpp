/*************************************************************************
    > File Name: 7-6.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月25日 星期四 19时22分53秒
 ************************************************************************/

#include "Header.hpp"
#include <limits.h>

int dp(vector<int>& coins,int amount)
{
    if(amount == 0)
    {
        return 0;
    }

    if(amount < 0)
    {
        return -1;
    }

    int ret = INT_MAX;

    for(auto e : coins)
    {
        int temp = dp(coins,amount - e);

        if(temp == -1)
        {
            continue;
        }

        ret = min(ret,temp + 1);
    }
    return ret;
}

int main()
{

    return 0;
}

