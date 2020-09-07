/*************************************************************************
# File Name: 9-7.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月07日 星期一 17时47分37秒
*************************************************************************/
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Cmp 
{
    public:
        bool operator()(pair<int,int> left,pair<int,int> right)
        {
            return left.second > right.second;
        }
};

int main()
{
    vector<int> arr {1,2,3,4,5,6,7,8,9,9,8,6,54,3,5,77,8,9,97,6,43,3,4,56,7,89};
    unordered_map<int,int> my_map;
    for(auto& e : arr)
    {
        my_map[e]++;
    }

    vector<pair<int,int>> map_arr(my_map.begin(),my_map.end());
    sort(map_arr.begin(),map_arr.end(),Cmp());

    for(auto& e : map_arr)
    {
        cout<<e.first<<" : "<<e.second<<endl;
    }
    return 0;
}
return left.second > right.second;
return left.second > right.second;
class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};

class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};

class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};

class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};

class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};

class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int, int>& m, pair<int, int>& n) 
        {
            return m.second > n.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(auto& e : nums)
        {
            my_map[e]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri;
        for(auto& e : my_map)
        {
            if(pri.size() < k)
            {
                pri.push(e);
            }
            else if(pri.size() == k)
            {
                if(pri.top().second < e.second)
                {
                    pri.pop();
                    pri.push(e);
                }
                else 
                {
                    continue;
                }
            }
        }

        vector<int> ret;
        while(!pri.empty())
        {
            ret.push_back(pri.top().first);
            pri.pop();
        }

        return ret;
    }
};
