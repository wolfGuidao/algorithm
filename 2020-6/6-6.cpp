/*************************************************************************
  > File Name: 6-6.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月30日 星期六 16时09分09秒
 ************************************************************************/

#include "Header.hpp"

#if 0
int main()
{
  int k,a,x,b,y;
  long long int count = 0;
  long long int c[101][101];
  while(cin>>k)
   {
   		cin>>a>>x>>b>>y;

      c[0][0] = 1;
      for(int i = 0;i <= 100;i++)
      {
        c[i][0] = 1;
        for(int j = 1;j <= 100;j++)
        {
          c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
        }
      }

      for(int i = 0;i <= k / a && i < x;i++)
      {
        if((k - i * a) % b == 0 && (k - i * a) / b <= y)
        {
          count =(count + (c[x][i] * c[y][(k - i * a) / b])% 1000000007) % 1000000007;
        }
      }
      cout<<count<<endl;
   }
  return 0;
}

#endif


const int mod = 1000000007;

int k;//总时长
int a,x,b,y;//a代表a歌曲的长度，x代表a歌曲的数量...
int dp[1010][210];//dp数组
int len[210];//存储每首歌的时长
int main()
{
    cin>>k;
    cin>>a>>x>>b>>y;
    int length = x + y;
    memset(dp,0,sizeof(dp));
    memset(len,0,sizeof(len));
    
    //base case
    dp[0][0] = 1;
    
    //根据每首歌的时长构造‘价值’数组
    for(int i = 1;i <= x;i++)
        len[i] = a;
    
    for(int i = x + 1;i <= length;i++)
        len[i] = b;
    
    //循环
    for(int i = 0;i <= k;i++)
    {   
        for(int j = 1;j <= length;j++)
    	{
    		//如果当前剩余歌曲的总时长大于单首歌曲的时长
    		//那么对于这首歌有可选和不选两种选择
    		//把组合的结果相加，都算满足情况
        	if(i >= len[j])
        	{
            	dp[i][j] = (dp[i][j - 1] + dp[i - len[j]][j - 1]) % mod;
        	}
        	//如果当前剩余歌曲的总时长小于单个个的时长
        	//代表不能选取这首歌，如果选取总时长就肯定会变长
        	//不满足情况
        	else
        	{
            	dp[i][j] = dp[i][j - 1] % mod;
        	}
    	}
    }
    cout<<dp[k][length]<<endl;
    return 0;
}

