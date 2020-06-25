/*************************************************************************
  > File Name: 7-3.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月19日 星期五 23时51分41秒
 ************************************************************************/

#include "Header.hpp"

#include <bits/stdc++.h>
using namespace std;


#if 0
int st[110], sum[110], dp[110][110]; 


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &st[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + st[i];
        dp[i][i] = 0;
    }
    for(int i = n; i >= 1; i --)
        for(int j = i + 1; j <= n; j++)
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
    printf("%d", dp[1][n]);
    return 0;
}
#endif 

#if 0
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;

int n;
int num[maxn]={0};
int dp[maxn][maxn]={0};
int cost[maxn][maxn]={0};

int main(){
    cin>>n;
    for(int i = 1;i <= n;i++)   cin>>num[i];

    memset(dp,0x3f,sizeof(dp));

    //花费初始化
    for(int i = 1; i <= n;i++)
    {
        for(int j = i; j <= n ;j++)
        {
            for(int k = i; k <= j; k++)
            {
                cost[i][j] += num[k];
            }
        }
    }

    for(int i = 1; i <= n ;i++)    dp[i][i] = 0;

    //枚举k  [l,r]->[l,k]+[k+1,r]
    for(int len = 2; len <= n;len++){
        for(int l = 1; l <= n-len+1 ;l++){
            int r = l+len-1;
            for(int k = l ; k < r; k++){
                dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]+cost[l][r]);
            }
        }
    }

    cout<<dp[1][n]<<endl;
    return 0;
}
#endif

//static int a=1;
//void fun1(void){ a=2; }
//void fun2(void){ int a=3; }
//void fun3(void){ static int a=4; }
//int main(int argc,char** args)
//{
//    printf("%d\n",a);
//    fun1( );
//    printf("%d\n",a);
//    fun2( );
//    printf("%d\n",a);
//    fun3( );
//    printf("%d\n",a);
//}

class A 
{
    public:
        A(int aa,int bb)
            :a(aa)
             ,b(bb)
    {}

        void Print()
        {
            cout<<a<<" : "<<b<<endl;
        }

        int a;
        int b;
};

int main()
{
    //A a(1,2);
    //a.Print();
    //int arr[5];
    //arr = {1,2,3,4};
    int num = 484;
    int sum = 0;
    for(int i = 1;sum < num;i += 2)
    {
        sum += i;
    }

    cout<<(sum == num)<<endl;
    return 0;
}

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1, false)); 
            dp[0][0] = true;

        // initialize 
        for (int i = 1; i <= m; ++ i)
        {
            if(p[i - 1] == '*' && dp[0][i - 1]) 
                dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1; i <= n; ++ i)
        {
            for (int j = 1; j <= m; ++ j)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];// ismatch, move on
                }
                else if (p[j - 1] == '*')
                {
                    bool zero, mul;// '*' act as zero, '*' act as multiple characters
                    zero = (j < m && s[i - 1] == p[j] && dp[i - 1][j - 1]) || dp[i][j - 1];
                    mul = dp[i - 1][j];
                    dp[i][j] = zero || mul;
                }
            }
        }

        return dp[n][m];
    }
};
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i, ++j;
            } else if (j < n && p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if (iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else return false;
        }
        while (j < n && p[j] == '*') ++j;//去除多余星号
        return j == n;
    }
};

