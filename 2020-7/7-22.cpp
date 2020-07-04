/*************************************************************************
  > File Name: 7-22.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月04日 星期六 22时18分23秒
 ************************************************************************/



#include "Header.hpp"

#include<iostream>
using namespace std;

int main()
{
    int k,a,x,b,y;
    long long int count = 0;
    long long int c[101][101];

    while(cin>>k)
    {
        cin>>a>>x>>b>>y;

        //初始化c数组
        //c[i][j]代表从i个里面选j个共有多少种选取方法
        c[0][0] = 1;
        for(int i = 1;i <= 100;i++)
        {
            c[i][0] = 1;
            for(int j = 1;j <= 100;j++)
            {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
            }
        }

        //开始计算
        for(int i = 0;i <= k / a && i <= x;i++)
        {
            //如果选取i个a歌单的歌曲，那么剩下的歌曲时间长度为k - i * a
            //如果满足剩下的时间可以在b中组合出来，并且需要b歌曲的数量
            //小于给定的y才可以
            //如果满足条件，count就等于在x个里选取i个A长度的歌的选法乘以
            //在y个里选取(k - i * a) / b个B长度的歌的选法
            //最后相加即可
            if((k - i * a) % b == 0 && (k - i * a) / b <= y)
                count = (count + (c[x][i] * c[y][(k - i * a) / b])
                        % 1000000007) % 1000000007; 
        }
        cout<<count<<endl;
    }
}




int main()
{

    return 0;
}

