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
#include <unordered_map>
using namespace std;

#if 0
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
#endif 

#if 0
int main()
{
    unordered_map<int,int> uu {{4,2},{0,1},{5,4}};
    sort(uu.begin(),uu.end(),[](pair<int,int> left,pair<int,int> right)
            {
                if(left.first == right.first)
                {
                    return left.second < right.second;
                }
                return left.first < right.first;
            });

    for(auto e : uu)
    {
        cout<<e.first<<" : "<<e.second;
    }
    cout<<endl;
    return 0;
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int map[1001],cur=0;
        memset(map,0,sizeof(map));
        for (int i=0;i<trips.size();i++){
            map[trips[i][1]] += trips[i][0];
            map[trips[i][2]] -= trips[i][0];
        }
        for (int i=0;i<1001;i++){
            cur += map[i];
            if (cur>capacity)
                return false;
        }
        return true;
    }
};
// 2 ~ 7
// 3 ~ 9
// 7 ~ 9
//map[2] = 3
//map[7] = -3
//map[3] = 8
//map[9] = -8
//map[7] = 0
//map[9] = -11
// 1 ~ 5
// 3 ~ 7
//map[1] = 2;
//map[5] = -2;
//map[3] = 3
//map[7] = -3 

#endif 

bool IsTrue(vector<int> ret,int val)
{
    for(auto e : ret)
    {
        if(e == val)
        {
            return false;
        }
    }
    return true;
}

void dfs(vector<int>& arr,vector<vector<int>>& ret,vector<int> track)
{
    if(track.size() == arr.size())
    {
        ret.push_back(track);
        return ;
    }

    for(int i = 0;i < arr.size();i++)
    {
        if(IsTrue(track,arr[i]))
           track.push_back(arr[i]);
        else 
            continue;

        dfs(arr,ret,track);
        track.pop_back();
    }
}

void backtrack(vector<int>& arr,vector<vector<int>>& ret,int index)
{
    if(index == arr.size())
    {
        ret.push_back(arr);
        return ;
    }

    for(int i = index;i < arr.size();i++)
    {
        swap(arr[i],arr[index]);
        backtrack(arr,ret,index + 1);
        swap(arr[i],arr[index]);
    }
}

int main()
{
    vector<int> arr { 1,4,4};
    vector<vector<int>> ret;
    vector<int> track;
    //dfs(arr,ret,track);
    backtrack(arr,ret,0);

    for(auto e : ret)
    {
        cout<<"[";
        for(auto m : e)
        {
            cout<<m<< " : ";
        }
        cout<<']'<<endl;
    }
    return 0;
}

class Solution {
public:
    void backtrack(vector<int>& candidates,vector<vector<int>>& ret,vector<int> track,int cursum,int prev,int target)
    {
        if(cursum >= target)
        {
            if(cursum == target)
                ret.push_back(track);
            
            return ;
        }

        for(int i = prev;i < candidates.size();i++)
        {
            track.push_back(candidates[i]);
            backtrack(candidates,ret,track,cursum + candidates[i],i,target);
            track.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
        {
            return {};
        }

        vector<vector<int>> ret;
        vector<int> track;
        backtrack(candidates,ret,track,0,0,target);

        return ret;
    }
};


class Solution {
public:
    void backtrack(string& tiles,string cur,unordered_set<string>& ret,vector<bool> visted)
    {
        if(!cur.empty())
        {
            ret.insert(cur);
        }

        //A         B               
        //AA  AB    BA  
        //AAB ABA BAA 
        for(int i = 0;i < tiles.size();i++)
        {
            if(visted[i] == false)
            {
                visted[i] = true;
                backtrack(tiles,cur + tiles[i],ret,visted);
                visted[i] = false;
            }
            
        }
    }

    int numTilePossibilities(string tiles) {
        if(tiles.empty())
        {
            return 0;
        }

        unordered_set<string> ret;
        vector<bool> visted(tiles.size(),false);
        backtrack(tiles,"",ret,visted);

        return ret.size();
    }
};
