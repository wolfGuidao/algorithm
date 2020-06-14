/*************************************************************************
    > File Name: 6-27.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月14日 星期日 19时32分48秒
 ************************************************************************/

#include "Header.hpp"


#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1e3+5;
char arr[maxn][maxn];
int n,m;
int sx,sy;          //人物起始位置
int bx,by;          //箱子起始位置
int ex,ey;
struct node{
    int x,y;        //当前点坐标
    int h,d;        //当前箱子坐标
    int step;
};
const int maxn_ = 55;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int vis[maxn_][maxn_][maxn_][maxn_];            //1 表示已经走过了
int bfs(int sx,int sy)
{
    queue<node> q;
    node f;                 //f表示队首
    f.x=sx;
    f.y=sy;
    f.h=bx;
    f.d=by;
    f.step=0;
    vis[sx][sy][bx][by]=1;  //一开始的状态标记为1
    q.push(f);              //将初始状态入队

    while(!q.empty())       //当队不空时
    {
       
        f=q.front();        //f接收队首

        if(f.h==ex && f.d==ey)      //如果队首坐标为E点坐标，则返回答案
        {
            return f.step;
        }
        q.pop();            //出队操作
        int nstep=f.step+1;     //下一步的步数为0
        int nbx=f.h;            //表示盒子的横坐标下一步的盒子假设还没移动
        int nby=f.d;          
        for(int i=0;i<4;++i)
        {
            int nx=f.x+dir[i][0];       //四个方向的某一个方向坐标
            int ny=f.y+dir[i][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]=='#')  //坐标不合法
            {
                continue;               //如果出界或者遇到墙，则坐标不合法
            }
            if(f.h==ex && f.d==ey)
            {
                node temp ;
                temp.x=nx;
                temp.y=ny;
                temp.step=f.step+1;
                q.push(temp);
            }
        
            if(nx==f.h && ny==f.d)    
            {
                int ox,oy;
                ox=nx+dir[i][0];  
                oy=ny+dir[i][1];
                if(ox<0 || ox>=n || oy<0 || oy>=m || arr[ox][oy]=='#' || arr[ox][oy]=='X')  //坐标不合法
                {
                    continue;
                }
                node temp;
                temp.x=nx;
                temp.y=ny;
                temp.h=ox;
                temp.d=oy;
                temp.step=nstep;
                if(!vis[temp.x][temp.y][temp.h][temp.d])
                {
                    q.push(temp);
                }
                vis[temp.x][temp.y][temp.h][temp.d]=1;
            }
            else if(arr[nx][ny]=='.' || arr[nx][ny]=='X' || arr[nx][ny]=='E')   //如过遇到的是.和X
            {
                node temp;
                temp.x=nx;
                temp.y=ny;
                temp.h=nbx;
                temp.d=nby;
                temp.step=nstep;
                if(!vis[nx][ny][nbx][nby])          //如果状态没遇到过，则入队
                {
                    q.push(temp);
                }
                vis[temp.x][temp.y][temp.h][temp.d]=1; //这个状态标记为1
            }
 
        }
    }
    return -1;
}
void judge(int i,int j)
{
    int flag1=0,flag2=0,flag3=0,flag4=0;
    if(i-1<0)
    {
        flag1=1;
    }else if(arr[i-1][j]=='#')
    {
        flag1=1;
    }
    if(j-1<0)
    {
        flag2=1;
    }else if(arr[i][j-1]=='#')
    {
        flag2=1;
    }
    if(i+1==n)
    {
        flag3=1;
    }else if(arr[i+1][j]=='#')
    {
        flag3=1;
    }
    if(j+1==m)
    {
        flag4=1;
    }else if(arr[i][j+1]=='#')
    {
        flag4=1;
    }
    if((flag1 && flag2) || (flag2 && flag3) || (flag3 && flag4) || (flag4 && flag1))
    {
        arr[i][j]='X';
    }
}
int main()
{
    memset(vis,0,sizeof(vis));
    while(cin>>n>>m)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s",arr+i);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(arr[i][j]=='S')
                {
                    sx=i;
                    sy=j; 
                }
                if(arr[i][j]=='0')
                {
                    bx=i;
                    by=j;
                    arr[i][j]='.';
                }
                if(arr[i][j]=='E')
                {
                    ex=i;
                    ey=j; 
                }     
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(arr[i][j]=='#' || arr[i][j]=='E') continue;
                judge(i,j);
            }
        }
        
        cout<<bfs(sx,sy)<<endl;
    }
    return 0;
}

int main()
{

    return 0;
}

