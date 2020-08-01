/*************************************************************************
# File Name: 8-15.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月01日 星期六 16时08分10秒
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 返回亲7数个数
     * @param digit int整型一维数组 组成亲7数的数字数组
     * @param digitLen int digit数组长度
     * @return int整型
     */
    
    vector<string> ret;
    
    bool IsExist(vector<string> ret,string track)
    {
        for(auto e : ret)
        {
            if(e == track)
            {
                return true;
            }
        }
        return false;
    }
    
    void backtrack(string& arr,int index,string track)
    {
        if(index == arr.size() - 1)
        {
           //if(!IsExist(ret,track))
                ret.push_back(track);
            return ;
        }
        
        for(int i = index;i < arr.size();i++)
        {
            swap(track[index],track[i]); 
            backtrack(arr,index + 1,track);
            swap(track[index],track[i]); 
        }
    }
    
    int reletive_7(int* digit, int digitLen) {
        // write code here
        string str;
        for(int i = 0;i < digitLen;i++)
        {
            str += to_string(digit[i]);
        }
        
        backtrack(str,0,str);

        for(auto e : ret)
        {
            cout<<e<<endl;
        }
        //sort(arr.begin(),arr.end());
        //int count = 0;
        //do 
        //{
        //    long long temp = 0;
        //    
        //    cout<<"[";
        //    for(auto e : arr)
        //    {
        //        cout<<e<<" ";
        //        temp = (temp * 10 + e);
        //    }
        //    cout<<"]"<<endl;
        //    
        //    cout<<"temp: "<<temp<<endl;
        //    if(temp % 7 == 0)
        //    {
        //        count++;
        //    }
        //}while(next_permutation(arr.begin(),arr.end()));
        //
        //return count;
    }
};


int main()
{
    int arr[] = {1,1,2};
    cout<<Solution().reletive_7(arr,3)<<endl;
    return 0;
}
