/*************************************************************************
# File Name: 8-8.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月22日 星期三 23时52分59秒
*************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int SumStr(string str)
    {
        int sum = 0;
        for(int i = 1;i <= str.size();i++)
        {
            sum += i;
        }
        return sum;
    }
    int numSub(string s) {
        int sum = 0;
        cout<<s<<endl;
        string str = "";
        for(auto e : s)
        {
            if(e == '1')
            {
                str += e;
            }
            else 
            {
                cout<<s<<endl;
                int temp = SumStr(str);
                sum += temp;

                temp = 0;
                str = "";
            }
        }
        if(!str.empty())
        {
            sum += SumStr(str);
        }
        return sum;
    }
};


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if(mat.empty())
        {
            return 0;
        }

        int m = (int)mat.size();
        int n = (int)mat[0].size();

        //dp[i][j]代表以i，j坐标为右端点，向左延续连续1的个数。意思是在第i行，j为终点，从j
        //向左连续1的个数，注意是连续连续连续
        vector<vector<int>> dp(m,vector<int>(n));

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                //处理边界
                if(j == 0)
                {
                    dp[i][j] = mat[i][j];
                }
                //如果当前位置为1，就代表可以在左边的基础上进行+1
                else if(mat[i][j] == 1)
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                //如果当前位置为0，那么dp代表的是连续1的个数，中间断了，直接赋值为0
                else 
                {
                    dp[i][j] = 0;
                }
            }
        }

        //保存最后的结果
        int sum = 0;

        //遍历，每次求以i，j坐标为右下角
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                //保存点i，j坐标处向左延续连续1的个数
                int num = dp[i][j];

                //向上枚举每一行
                for(int k = i;k >= 0;k--)
                {
                    //一旦某一行为0，那么求min后都为0，代表没有构成矩阵
                    if(num == 0)
                    {
                        break;
                    }
                    //更新结果
                    num = min(num,dp[k][j]);
                    sum += num;
                }
            }
        }
        return sum;
    }
};


int main()
{
    cout<<Solution().numSub("111")<<endl;;
    return 0;
}
