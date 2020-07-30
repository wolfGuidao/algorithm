/*************************************************************************
# File Name: 8-13.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月29日 星期三 14时18分30秒
*************************************************************************/
#include <iostream>
using namespace std;

#if 0
void Print(int& a)    
{    
    cout<<a<<endl;    
}    
    
void Print(int* a)    
{    
    cout<<*a<<endl;    
}    
    
    
int main()    
{    
    int a = 999;    
    int& ra = a;    
    int* pa = &a;    
    Print(ra);    
    Print(pa);    
    return 0;    
}    

#include <signal.h>
#include <pthread.h>

void Handler(int sig)
{
    cout<<'i am: '<<sig<<endl;
    exit(1);
}

void* ThreadEntry(void* arg)
{
    (void)arg;
    while(1)
    {
       signal(2,Handler); 
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,ThreadEntry,nullptr);
    pthread_join(tid,nullptr);
    return 0;
}
#endif 
#include <iostream>
#include <vector>
using namespace std;

#if 1
class Solution {
public:
    //vector<vector<int>> dir {{-1,0},{0,-1},{1,0},{0,1}};

    void DFS(vector<vector<char>>& grid,int x,int y,vector<vector<bool>> visted)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
        {
            cout<<"["<<x<<" : "<<y<<"]"<<" is bad"<<endl;
            return ;
        }

        //
        grid[x][y] = '0';
        cout<<"["<<x<<" : "<<y<<"]"<<" is ok"<<endl;
        //visted[x][y] = true;

        //for(auto e : dir)
        //{
        //    int new_x = x + e[0];
        //    int new_y = y + e[1];
        //    DFS(grid,new_x,new_y,visted);
        //}
        
        //if(x + 1 < grid.size() && grid[x + 1][y] == '1')
            DFS(grid,x + 1,y,visted);
        //if(x - 1 >= 0 && grid[x - 1][y] == '1')
            DFS(grid,x - 1,y,visted);
        //if(y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            DFS(grid,x,y + 1,visted);
        //if(y - 1 >= 0 && grid[x][y - 1] == '1')
            DFS(grid,x,y - 1,visted);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int ret = 0;
        vector<vector<bool>> visted(grid.size(),vector<bool>(grid[0].size(),false));
        for(size_t i = 0;i < grid.size();i++)
        {
            for(size_t j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ret++;
                    DFS(grid,i,j,visted);
                }
            }
        }
        return ret;
    }
};
#endif

#if 0
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
#endif

int main()
{
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<Solution().numIslands(grid)<<endl;
    return 0;
}

/*
class Solution {
public:

    void DFS(vector<vector<char>>& grid,int x,int y)
    {
       //
        grid[x][y] = '0';

        if(x + 1 < grid.size() && grid[x + 1][y] == '1')
              DFS(grid,x + 1,y);
          if(x - 1 >= 0 && grid[x - 1][y] == '1')
              DFS(grid,x - 1,y);
           if(y + 1 < grid[0].size() && grid[x][y + 1] == '1')
              DFS(grid,x,y + 1);
          if(y - 1 >= 0 && grid[x][y - 1] == '1')
              DFS(grid,x,y - 1); 
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int ret = 0;
        
        for(size_t i = 0;i < grid.size();i++)
        {
            for(size_t j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ret++;
                    DFS(grid,i,j);
                }
            }
        }
        return ret;
    }
};
*/

/*
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
*/

/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int ret = 0;
        queue<pair<int,int>> que;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ret++;

                    
                    que.push({i,j});
                    grid[i][j] = '0';

                    while(!que.empty())
                    {
                        pair<int,int> temp = que.front();
                        que.pop();
                        int index_x = temp.first;
                        int index_y = temp.second;

                        if(index_x + 1 < grid.size() && grid[index_x + 1][index_y] == '1')
                        {
                            que.push({index_x + 1,index_y});
                            grid[index_x + 1][index_y] = '0';
                        }
                           
                        if(index_x - 1 >= 0 && grid[index_x - 1][index_y] == '1')
                        {
                            que.push({index_x - 1,index_y});
                            grid[index_x - 1][index_y] = '0';
                        }
                            
                        if(index_y + 1 < grid[0].size() && grid[index_x][index_y + 1] == '1')
                        {
                            que.push({index_x,index_y + 1});
                            grid[index_x][index_y + 1] = '0';
                        }
                            
                        if(index_y - 1 >= 0 && grid[index_x][index_y - 1] == '1')
                        {
                            que.push({index_x,index_y - 1});
                            grid[index_x][index_y - 1] = '0';
                        }
                           
                    }
                }
            }
        }
        return ret;
    }
};<Paste>
