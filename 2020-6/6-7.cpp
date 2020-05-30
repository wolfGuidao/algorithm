/*************************************************************************
  > File Name: 6-7.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月30日 星期六 16时49分05秒
 ************************************************************************/

#include "Header.hpp"

//用户输入的目标图案
vector<vector<char>> str;
//行列
int n,m;

//遇到Y的处理
void dfs_Y(int x,int y)
{
  if(x >= 0 && x < n && y >= 0 && y < m && (str[x][y] == 'Y'|| str[x][y] == 'G'))
  {
    if(str[x][y] == 'G')
    {
      str[x][y] = 'B';
    }
    else 
    {
      str[x][y] = 'X';
    }

    dfs_Y(x - 1, y - 1);
    dfs_Y(x + 1, y + 1);
  }
  return ;
}

//遇到字符B的处理
void dfs_B(int x,int y)
{
  //判断下标是否越界并且是B或者G字符
  if(x >= 0 && x < n && y >= 0 && y < m && (str[x][y] == 'B' || str[x][y] == 'G'))
  {
    if(str[x][y] == 'G')
      str[x][y] = 'Y';
    else
      str[x][y] = 'X';
    //递归往右上和左下判断
    dfs_B(x + 1,y - 1);
    dfs_B(x - 1,y + 1);
  }
  return ;
}

int main()
{
  int cnt=0;
  cin>>n>>m;

  str = vector<vector<char>>(n,vector<char>(m));
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < m;j++)
    {
      cin>>str[i][j];
    }
  }

  //循环遍历目标图案
    for(int i = 0;i < n;i++)
    {
       for(int j = 0;j < m;j++)
       {
           if(str[i][j] == 'Y')
           {
               dfs_Y(i,j);
               cnt++;
           }
           else if(str[i][j] == 'B')
           {
               dfs_B(i,j);
               cnt++;
           }
           else if(str[i][j] == 'G')
           {
               dfs_Y(i,j);
               //str[i][j]='B';
               dfs_B(i,j);
               cnt += 2;
           }
       }
    }
    cout<<cnt<<endl;
  return 0;
}

