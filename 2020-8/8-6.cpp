/*************************************************************************
# File Name: 8-6.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月18日 星期六 21时07分41秒
 *************************************************************************/

#include <iostream>
#include <unistd.h>
using namespace std;
using INT = int;

#if 0
void* ThreadEntry(void* arg)
{
    (void)arg;
    while(1)
    {
        cout<<"i am child thread"<<endl;
        sleep(1);

    }
}
#pragma pack(8)
struct Num 
{
    char c;
    char a;
    int b;
    int* d;
};

static int a = 999;
#include <deque>
#include <map>
#include <set>
#include <list>

void Func(int&& a)
{
    cout<<a<<endl;
    cout<<"Func1"<<endl;
}
void Func(int a)
{
    cout<<a<<endl;
    cout<<"Func2"<<endl;
}



int main()
{
    //pthread_t tid;
    //pthread_create(&tid,nullptr,ThreadEntry,nullptr);
    ////pthread_join(tid,nullptr);
    //static int a = 666;
    //cout<<a<<endl;
    //set<int> arr{1,2,3,4,5,56,7,8};
    //for(auto e : arr)
    //{
    //    cout<<e<<" ";
    //}
    //cout<<endl;

    //auto it = arr.begin();
    //while(it != arr.end())
    //{
    //    it = arr.erase(it);
    //}
    //cout<<"after"<<endl;
    //for(auto e : arr)
    //{
    //    cout<<e<<" ";
    //}
    //cout<<sizeof(long)<<endl;
    //INT i = 999;
    // cout<<i<<endl;

    // int num = 999;
    // Func(num);
    //
    int&& pa = 100;
    auto func = [&]()
    {
        cout<<pa<<endl;
        Func(std::forward<int>(pa));
    };
    func();
    return 0;
}

#endif 

#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int maxpro = 100;  //最大进程数
const int maxres = 100;  //最大资源数
 
int pro; //进程数
int res; //资源数
 
int request[maxres];//进程请求资源数目
//int R[maxres]; //总资源
int V[maxres]; //可提供
int C[maxpro][maxres]; //总需求
int A[maxpro][maxres]; //已分配
int vis[maxpro]; //表示第i个进程是否已分配资源，1表示已分配
int path[maxpro];  //路径
 
 
//安全状态判断
bool safe() {
    int curV[maxres]; //目前可提供资源
    for(int i = 0; i < res; i++)
        curV[i] = V[i];
 
    memset(vis, 0, sizeof(vis));
 
    int flag = 1;
    for(int i1 = 0; i1 < pro; i1++) {
        int i;
        for(i = 0; i < pro; i++) {
            if(vis[i] == 1) continue;
            int flagpro = 1; //0表示未找到合适的进程
            for(int j = 0; j < res; j++) {
                if(C[i][j] - A[i][j] > curV[j]) {
                    flagpro = 0; break;
                }
            }
            if(flagpro) {
                path[i1] = i;
                vis[i] = 1;
                for(int k = 0; k < res; k++)
                    curV[k] += A[i][k];
                break;
            }
        }
        if(i == pro) {
            flag = 0;
        }
    }
 
    return flag == 1;
}
 
void print() {
    cout << endl << "显示当前状态" << endl;
    cout << "总需求矩阵C" << endl;
    for(int i = 0; i < pro; i++) {
        for(int j = 0; j < res; j++) {
            printf("%2d ", C[i][j]);
        }
        cout << endl;
    }
 
    cout << "已分配矩阵A" << endl;
    for(int i = 0; i < pro; i++) {
        for(int j = 0; j < res; j++) {
            printf("%2d ", A[i][j]);
        }
        cout << endl;
    }
 
    cout << "需求矩阵N (C-A)" << endl;
    for(int i = 0; i < pro; i++) {
        for(int j = 0; j < res; j++) {
            printf("%2d ", C[i][j] - A[i][j]);
        }
        cout << endl;
    }
 
   /* cout << "总资源向量R" << endl;
    for(int i = 0; i < res; i++)
        cout << R[i] << ' ';
    cout << endl;*/
 
    cout << "可提供资源向量V" << endl;
    for(int i = 0; i < res; i++)
        cout << V[i] << ' ';
    cout << endl << endl;
}
 
void bank() {
    while(true) {
        cout << endl << "请求资源输入1，显示当前状态输入2, 结束输入3" << endl;
        int k;
        cin >> k;
        if(k == 3) break;
        else if(k == 2) {
            print(); continue;
        }
        cout << "请输入请求资源的进程编号, 进程号为0 - " << pro - 1 << endl;
        int proindex;
        cin >> proindex;
        cout << "请输入此进程每个资源需求数目" << endl;
        for(int i = 0; i < res; i++)
            cin >> request[i];
 
        //检查该进程所需要的资源是否已超过它所宣布的最大值
        int flag = 1;  //flag为1表示没超过，为0表示超过
        for(int i = 0; i < res; i++) {
            if(request[i] + A[proindex][i] > C[proindex][i])
                flag = 0;
        }
        if(flag == 0) {
            cout << "资源请求失败，该进程所需要的资源已超过总资源的最大值" << endl;
            continue;
        }
 
        //检查系统当前是否有足够资源满足该进程的请求
        flag = 1;  //flag为1有足够资源，为0表示没有
        for(int i = 0; i < res; i++) {
            if(request[i] > V[i])
                flag = 0;
        }
        if(flag == 0) {
            cout << "资源请求失败，系统当前没有有足够资源满足该进程的请求" << endl;
            continue;
        }
 
        //尝试分配资源给该进程，得到新的状态
        for(int i = 0; i < res; i++) {
            A[proindex][i] += request[i]; //已分配资源矩阵A更新
            V[i] -= request[i]; //可提供资源向量V更新
        }
 
        //执行安全性算法，若该新状态是安全的，则分配完成；若新状态是不安全的，则恢复原状态，阻塞该进程
        if(safe()) {
            cout << "资源分配成功" << endl;
            cout << "安全路径是：";
            for(int i = 0; i < pro; i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < pro; i++) {
                int j;
                for(j = 0; j < res; j++) {
                    if(A[i][j] != C[i][j])
                        break;
                }
                if(j == res)
                {
                    for(j = 0; j < res; j++) {
                        V[j] += A[i][j];
                        A[i][j] = 0;
                    }
                }
            }
        }
        else  {
            cout << "该状态不安全，资源分配失败" << endl;
            for(int i = 0; i < res; i++) {
                A[proindex][i] -= request[i]; //已分配资源矩阵A更新
                V[i] += request[i]; //可提供资源向量V更新
            }
        }
    }
}
 
int main()
{
    cout << "请输入总资源数: " << endl;
    cin >> res;
    cout << "请输入总进程数: " << endl;
    cin >> pro;
/*
    cout << "请分别输入每个资源的数目(R向量)，目前有" << res << "个资源" << endl;
    for(int i = 0; i < res; i++)
        cin >> R[i];*/
 
    cout << "请分别输入每个资源的已分配数目(V向量），目前有" << res << "个资源" << endl;
    for(int i = 0;  i< res; i++)
        cin >> V[i];
 
    cout << "请输入总需求矩阵C，共有" << res << "个资源，" << pro << "个进程" << endl;
    cout << "格式: 每行输入单个进程的总需求资源数目, 输入" << pro << "行" << endl;
    for(int i = 0; i < pro; i++)
        for(int j = 0 ; j < res; j++)
            cin >> C[i][j];
 
    cout << "请输入已分配矩阵A，共有" << res << "个资源，" << pro << "个进程" << endl;
    cout << "格式: 每行输入单个进程的已分配资源数目, 输入" << pro << "行" << endl;
 
    for(int i = 0; i < pro; i++)
        for(int j = 0 ; j < res; j++)
            cin >> A[i][j];
 
    bank();
    return 0;
}
 
