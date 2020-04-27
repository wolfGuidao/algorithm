/*
 *
 *画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。

 小Q有他独特的绘画技巧,每次小Q会选择一条斜线, 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的一段格子,都涂画为蓝色,用'B'表示;

 如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。

 如果一个格子既被蓝色涂画过又被黄色涂画过,�
 * */


#include <iostream>
#include <vector>
using namespace std;

//用户输入的目标图案
vector<vector<char>> str;
//行列
int n,m;

//遇到Y的处理
void dfs_Y(int x,int y)
{
  //判断下标是否越界并且是字符Y或G
  if(x >= 0 && x < n && y >= 0 && y < m && (str[x][y] == 'Y' || str[x][y] == 'G'))
  {
    if(str[x][y] == 'G')
      str[x][y] = 'B';
    else
      str[x][y] = 'X';
    //往左上和右下递归判断
    dfs_Y(x - 1,y - 1);
    dfs_Y(x + 1,y + 1);
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
        str[i][j]='B';
        dfs_B(i,j);
        cnt += 2;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}

