/*************************************************************************
# File Name: 9-11.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月12日 星期六 10时12分48秒
*************************************************************************/
#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> boy_id = {1,2,3};
    vector<int> gilr_id = {4,5,6};
    int n = 6;
    vector<pair<int,int>> info = {{0,4},{0,3},{1,3},{1,4},{2,5},{2,4}};

    int ret = 0;
    for(auto& e : info)
    {
        int temp = 1;
        unordered_map<int,int> my_map;
        my_map[e.first]++;
        my_map[e.second]++;
        vector<pair<int,int>> copy_info(info);
        for(int j = 0;j < copy_info.size();j++)
        {
            int boy = copy_info[j].first;
            int gril = copy_info[j].second;
            if(my_map.count(boy) == 1 || my_map.count(gril) == 1)
            {
                continue;
            }
            else 
            {
                temp++;
                my_map[boy]++;
                my_map[gril]++;
                cout<<"boy： "<<boy<<"gril: "<<gril<<endl;
            }
        }
        ret = max(ret,temp);
    }
    cout<<ret<<endl;
    return 0;
}
