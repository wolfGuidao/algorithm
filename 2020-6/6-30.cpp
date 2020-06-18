/*************************************************************************
    > File Name: 6-30.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月16日 星期二 12时49分01秒
 ************************************************************************/

// #include "Header.hpp"

#if 0
int func(int a)
{
    cout<<a<<endl;
    return a;
}

template<class T1,class T2>
auto Add(T1 a,T2 b)->decltype(a + b)
{
    return a + b;
}

int main()
{
    //vector<int> arr {1,2,3,4,5,6};
    //vector<int>::iterator it = arr.begin(); 
    //cout<<*it<<endl;
    //decltype(1 + 2) b ;
    //cout<<typeid(b).name()<<endl;
    //cout<<typeid(decltype(func)).name()<<endl;
    //cout<<typeid(decltype(func(b))).name()<<endl;
    //cout<<Add(1,99)<<endl;
    //cout<<typeid(decltype(Add(1,2))).name()<<endl;
    const int& a = 999;
    int&& b = a + 1;
    b += 999;
    cout<<a<<&a<<endl;
    cout<<b<<&b<<endl;
    //int&& c = b;
    return 0;
}
#endif

#if 0
#include <atomic>
#include <thread>

void ThreadEntry1(int a)
{
    while(1)
    {
        sleep(1);
        a++;
        cout<<a<<endl;
    }
}

void ThreadEntry2(int a)
{
    while(1)
    {
        sleep(1);
        a++;
        cout<<a<<endl;
    }
}

int main()
{
    int a = 999;
    thread t1(ThreadEntry1,a);
    thread t2(ThreadEntry2,a);
    t1.join();
    t2.join();
    return 0;
}
#endif 

#if 0
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

int main()
{
    vector<string> output;
    string str = "i am wolf muma";
    split(output,str,boost::is_any_of(" "),boost::token_compress_on);    
    for(size_t i = 0;i < output.size();i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
#endif

#if 0
include <bits/stdc++.h>
//#include <ctemplate/template.h>
#include <jsoncpp/json/json.h>
using namespace std;

int main()
{
    Json::Value value;
    value["name"] = "wolf";
    value["age"] = 18;
    value["sex"] = "man";

    string json_document = "{\"age\" : 123, \"name\" : \"weng\"}";
    Json::Reader reader;
    Json::Value info;
    reader.parse(json_document,info);
    cout<<info["name"]<<" : "<<info["age"]<<endl;
    Json::FastWriter writer;
    string str = writer.write(value);
    cout<<str<<endl;
    return 0;
}

#endif]

#include <bits/stdc++.h>
using namespace std;

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        // 0 必拿
        int ret = 0;
        int max_left = INT_MIN;
        int max_right = INT_MIN;
        for(size_t i = 0;i < n;i++)
        {
            if(left[i] == 0)
            {
                ret += right[i];
                right[i] = 0;
            }
            max_right = max(max_right,left[i]);
            if(right[i] == 0)
            {
                ret += left[i];
                left[i] = 0;
            }
            max_left = max(max_left,left[i]);
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        
        int count = 0;
        if(max_left >= max_right)
        {
            int flag = 1;
            for(size_t i = 0;i < right.size();i++)
            {
                if(right[i] != 0 && flag)
                {
                    ret += 1;
                    flag = 0;
                }
                else if(right[i])
                {
                    ret += right[i];
                }
            }
            
            
        }
        else 
        {
            int flag = 1;
            for(size_t i = 0;i < left.size();i++)
            {
                if(left[i] != 0 && flag)
                {
                    ret += 1;
                    flag = 0;
                }
                else if(left[i])
                {
                    ret += left[i];
                }
            }
        }
        return ret + 1;
    }
};


int main()
{
    int n = 3;
    vector<int> left = {5,6,7};
    vector<int> right = {4,5,6};
    cout<<Gloves().findMinimum(n,left,right)<<endl;
    return 0;
}
