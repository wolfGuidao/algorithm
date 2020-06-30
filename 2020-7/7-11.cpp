/*************************************************************************
  > File Name: 7-11.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月30日 星期二 16时59分08秒
 ************************************************************************/

#include "Header.hpp"

# include <iostream>
# include <vector>

using namespace std;
  
int main()
{
    int n ;
    while(cin>>n)
    {
        vector<int> gym(n);
        vector<int>work(n);
        for ( i=0; i<n; ++i )
            cin>>work[i];
        
        for( i=0; i<n; ++i )
            cin>>gym[i];
        
        vector<vector<int>> dp(n + 1,vector<int>(3,0)); // 0是休息，1是锻炼，2是工作
 		//遍历天数
        for ( int i=1; i<=n; ++i )
        {
            if ( gym[i-1] == 1 )
            {
                // 可以锻炼，选休息和工作最小的
                dp[i][1] = min( dp[i-1][0], dp[i-1][2] );
            }
            if ( work[i-1] == 1 )
            {
                // 可以工作，选休息和锻炼最小的
                dp[i][2] = min( dp[i-1][0], dp[i-1][1] );
            }
			//可以休息，选工作和锻炼最小的 +1
            dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
        }
		
		//返回结果
        int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
        cout<<res<<endl;
    }

}

