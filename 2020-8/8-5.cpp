/*************************************************************************
# File Name: 8-5.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月17日 星期五 14时40分06秒
*************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#if 0
using INT = int;

void Func()
{
    throw string("i am Func()");
    cout<<"i am test Func"<<endl;
}

int main()
{
    //try 
    //{
    //    Func();
    //    cout<<"i am try after"<<endl;
    //}
    //catch(string ex)
    //{
    //    cout<<ex<<endl;
    //}
    //cout<<"i am catch after"<<endl;
    //int a = 999;
    //int&& aa = move(a);
    //a += 1;
    //cout<<a<<endl;
    //cout<<aa<<endl;
    INT a = 999;
    cout<<a<<endl;
    return 0;
}o

#endif 

#include <stdio.h>
#include <string.h>
#include <vector>

int main()
{
    int n,m,c0,d0;
    
    while(cin>>n>>m>>c0>>d0)
    {
    	vector<int> arr(10000);
    	vector<int> weight(10000);
    	vector<int> value(10000);
    	//
        int index = 0;
        int num = n / c0;
        while(num--)
        {
            weight[index] = c0;
            value[index] = d0;
            index++;
        }

		int all_num,cons_stu,cons_flo,child_value;
        while(m--)
        {
            cin>>all_num>>cons_stu>>cons_flo>>child_value;
            
            num = min(n / cons_flo,all_num / cons_stu);
            
            while(num--)
            {
                weight[index] = cons_flo;
                value[index] = child_value;
                index++;
            }
        }
        
        m = index;
        vector<int> dp(10000,0);
        dp[0]=0;
        
        for(int i = 0;i < m;i++)
        {
            for(int j = n;j >= weight[i];j--)
            { 
                dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
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

