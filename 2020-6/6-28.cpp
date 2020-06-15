/*************************************************************************
  > File Name: 6-28.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月15日 星期一 13时01分38秒
 ************************************************************************/

#include "Header.hpp"
#include <map>

#if 0
static int a;
int b;

struct Node 
{
    Node(int aa,int bb)
    {
        a = aa;
        b = bb;
    }
    int a;
    int b;
};

int main()
{
    //static int c;
    //int d;
    //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<endl;
    //const int e = 1;
    //auto& f = e;
    //map<int,int> mp;
    //for(int i = 0;i < 10;i++)
    //{
    //    mp[i] = random();
    //}

    //sort(mp.begin(),mp.end(),[](pair<int,int>left,pair<int,int>right)
    //        {
    //            return left.second > right.second;
    //        });

    //for(auto it = mp.begin();it != mp.end();it++)
    //{
    //    cout<<it->first<<" ";
    //}

    //vector<int> arr{4,6,11,67,15,973,2862,157,151};
    //sort(arr.begin(),arr.end(),[](int a,int b)
    //        {
    //            return a < b;
    //        });

    //vector<Node> arr{{1,5},{52,67},{14,176}};
    //sort(arr.begin(),arr.end(),[](Node a,Node b)
    //        {
    //            return a.b > b.b;
    //        });

    //for(auto i = 0;i < arr.size();i++)
    //{
    //    cout<<arr[i].a<<" ";
    //}
    return 0;
}
#endif
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    int x ;
    cin>>n>>x;
    long* person_now = new long[n];
    long min_value = INT_MAX;

    for(int i=0; i<n; i++) 
    {
        cin>>person_now[i];
        min_value = min(min_value, person_now[i]);
    }

    int index = x-1;
    int count = 0;

    while(person_now[(index+n)%n]!=min_value) {
        person_now[(index+n)%n] -= min_value+1;
        index--;
        count++;
    }
    person_now[(index+n)%n] = min_value*n + count;
    index--;
    while((index+n)%n!=x-1) {
        person_now[(index+n)%n] -= min_value;
        index--;
    }
    for(int i=0; i<n; i++) {
        cout<<person_now[i]<<" ";
    }



    return 0;
}
