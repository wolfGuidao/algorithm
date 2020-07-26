/*************************************************************************
# File Name: 8-5.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月17日 星期五 14时40分06秒
*************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//代表面粉的总克数
	int n;

	//粽子（馅料的总数）
	int m;
	
	//不放馅料做粽子消耗面粉的克数
	int c0;
	
	//不放馅料做粽子的收益
    int d0;
    
    while(cin>>n>>m>>c0>>d0)
    {
		//weight[i]代表做第i种粽子消耗面粉的克数
    	vector<int> weight(10000);

		//value[i]代表做第i种粽子消耗面粉的收益
    	vector<int> value(10000);
    	
    	//标记总的粽子的个数（第一大类和第二大类共可以作出的粽子个数）
        int index = 0;

		//num代表第二大类粽子的总个数：面粉总克数 ／ 消耗面粉的克数
        int num = n / c0;
        while(num--)
        {
        	//每种粽子消耗c0克面粉
            weight[index] = c0;

			//收益d0
            value[index] = d0;
            index++;
        }

		//代表每种粽子总馅料的克数
		int all_num;
	
		//代表做第i种粽子消耗第i种馅料的克数
		int cons_stu;

		//代表做第i种粽子消耗面粉的克数
		int cons_flo;
		
		//代表作出第i种粽子的收益
		int child_value;

		//循环输入
        while(m--)
        {
            cin>>all_num>>cons_stu>>cons_flo>>child_value;
            
            //num记录min(n / cons_flo,all_num / cons_stu)的最小值
            //因为这里的粽子是第一大类，其受面粉和馅料的限制，只能取较小的
            num = min(n / cons_flo,all_num / cons_stu);
            
            while(num--)
            {
            	//更新作出每种粽子消耗面粉的克数
                weight[index] = cons_flo;
	
				//更新做出每种粽子的收益
                value[index] = child_value;
                index++;
            }
        }
        
        //index记录的是总粽子的个数，更新一下即可
        m = index;

		//dp数组，到这里已经完全转化为01背包问题了，
		//直接一01背包的解法即可
        vector<int> dp(10000,0);
        dp[0]=0;
        for(int i = 0;i < m;i++)
        {
        	/*
            for(int j = n;j >= weight[i];j--)
            { 
                dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
            }
            */

			//这种写法已经完全和《01背包问题详解》一致了
            for(int j = n;j >= 0;j--)
            { 
            	if(j < weight[i])
            	{
            		dp[j] = dp[j - 1];
            	}
            	else 
            	{
            		dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
            	}
            }
        }
        
        int ret = 0;
        for(auto e : dp)
        {
           ret = max(e,ret);
        }
        cout<<ret<<endl;
    }
    return 0;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
        {
            return true;
        }
        if(wordDict.empty())
        {
            return false;
        }

        unordered_map<string,int> word_map;
        for(auto e : wordDict)
        {
            word_map[e]++;
        }

        //dp[i]代表从0到i - 1之间到字符串满足情况  
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        //枚举每一个位置
        for(int i = 1;i <= s.size();i++)
        {
            //再次枚举[0,j -  1]和[j,i - 1]两个子串，如果有一种满足情况即为true
            for(int j = 0;j < i;j++)
            {
                if(dp[j] && word_map.count(s.substr(j,i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
