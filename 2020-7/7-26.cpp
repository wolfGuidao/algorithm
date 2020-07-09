/*************************************************************************
  > File Name: 7-26.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月09日 星期四 16时05分41秒
 ************************************************************************/

#include "Header.hpp"

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


inline bool ishu(vector<int>num)
{
    if(num.empty()) 
        return true;
    
    int count0 = 0;
    
    //统计牌集合中第一张牌上数字在整个牌集合中出现的次数count0
    count0 = count(num.begin(),num.end(),num[0]);
    
    //雀头 
    //num.size()%3 != 0是用来判断一旦选了雀头下次就不能选了
    //因为牌共有14张，要么去掉雀头两张剩12张（12 % 3 == 0）
    //要么去掉顺子或刻子3张还剩11张（11 % 3 ！= 0）
    //count0 >= 2是用来判断第一张牌数量是否大于等于2（雀头是2张）
    if(num.size()%3 != 0 && count0 >= 2)
    {
    	//去掉雀头的两张相同的牌继续递归判断
        vector<int> newnum(num.begin() + 2,num.end());
        
        if(ishu(newnum)) 
        	return true;
    }
    
    //刻子
    //第一张牌的数量大于等于3张才有可能是刻子 
    if(count0 >= 3)
    {
    	//去掉刻子的3张相同的牌继续判断
        vector<int> newnum(num.begin()+3,num.end());
        
        if(ishu(newnum)) 
        	return true;
    }
    
    //顺子 
    //注意走到这里并不代表count0 == 1,（牌面是1---9，所以可以直接进行+1来判断）
    //如果下一张牌和下下一张牌的数量出现的次数超过一，那么这种情况是有可能构成顺子的
    if(count(num.begin(),num.end(),num[0] + 1) > 0 && 
    					count(num.begin(),num.end(),num[0] + 2) > 0)
    {
    	//找到构成顺子的3张牌，删掉继续判断
        vector<int> newnum(num.begin() + 1,num.end());
        newnum.erase(find(newnum.begin(),newnum.end(),num[0] + 1));
        newnum.erase(find(newnum.begin(),newnum.end(),num[0] + 2));
        
        if(ishu(newnum)) 
        	return true;
    }
    return false;
}

//num是原本牌的集合，x是枚举的牌
inline bool hupai(vector<int> num,int x)
{
	//过滤
    if(count(num.begin(),num.end(),x) == 4)
        return false;
    
    //放到牌的集合当中
    num.push_back(x);

	//进行一次排序
    sort(num.begin(),num.end());
    
    //进行判断
	return ishu(num);
}

int main()
{
    vector<int> num(13),ans;
    for(int i = 0;i < 13;++i)
    {
        cin>>num[i];
    }
    
    for(int i = 1;i <= 9;++i)
    {
        if(hupai(num,i)) 
            ans.push_back(i);
    }
    
    if(ans.size() == 0) 
    	puts("0");
    else
    {
        for(int i = 0;i < ans.size();++i)
            cout<<ans[i]<<" ";
    }
    
    return 0;
}
