/*************************************************************************
  > File Name: 7-5.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月24日 星期三 16时44分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#if 0
void GetSort(vector<int>& arr,int k,int n)
{
    int count = k;
    vector<int> temp(arr);
    while(count > 0)
    {
        vector<int> left(n);
        vector<int> right(n);

        for(size_t i = 0;i < 2 * n;i++)
        {
            if(i < n)
            {
                left[i] = temp[i]; 
            }
            else
            {
                right[i % n] = temp[i];
            }
        }

        int left_index = n - 1;
        int right_index = n - 1;
        int index = 0;

        int num = n - 1;
        /*
           while(right_index >= 0 || left.size() >= 0)
           {
           arr[index++] = right[right_index--];
           arr[index++] = left[left_index--];
           }
           */
        while(n >= 0)
        {
            temp[index++] = right[n];
            temp[index++] = left[n];
            n--;
        }
        count--;
    }
    for(int i = 2 * n - 1;i >= 0;i--)
    {
        cout<<temp[i]<<" ";
    }
}

int main()
{
    int T;
    cout<<"flag"<<endl;
    while(cin>>T)
    {
        int n;
        int k;
        cin>>n>>k;

        vector<int> arr(2 * n);
        for(int i = 0;i < 2 * n;i++)
        {
            cin>>arr[i];
        }

        GetSort(arr,k,n);
    }
    return 0;
}

#endif 

class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
            if (S == T) 
                return 0;

            int N = routes.size();
            map<int, set<int> > m; // 存储车站能通到哪些路线
            
            for (int i = 0; i < N; ++i) 
            {
                for (auto j : routes[i])
                {
                    m[j].insert(i);
                }
            }

            vector<bool> visited(N, false); // 哪些路线被遍历过了
            queue<int> q; // 存储已经遍历过的路线
            //队列中保存的是起点S所能到达的车站
            for (auto x : m[S]) 
            {
                q.push(x);
                visited[x] = true;
            }

            //计数
            int step = 0;
            while (!q.empty()) 
            {
                ++step;
                int s = q.size();
                for (int i = 0; i < s; ++i)
                {
                    int t = q.front();
                    q.pop();

                    //遍历S到达的车站是否存在目标车站T，如果存在，直接返回反之把当前车站所能到达的车站继续入队
                    for (auto j : routes[t]) 
                    {
                        if (j == T) 
                            return step;
                        
                        for (auto x : m[j]) 
                        {
                            if (!visited[x])
                            {
                                q.push(x);
                                visited[x] = true;
                            }
                        }
                    }
                }
            }
            return -1;
        }
};


