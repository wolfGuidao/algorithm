/*************************************************************************
# File Name: 8-2.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月15日 星期三 11时15分49秒
*************************************************************************/
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <limits.h>
using namespace std;

int Rand5()
{
    return rand() % 5 + 1;
}

int Rand7()
{
    int num = INT_MAX;
    while(num > 21)
    {
        num = 5 * (Rand5() - 1) + Rand5();
    }
    return rand() % 7 + 1;
}

int main()
{
    srand((unsigned)time(NULL));
    while(1)
    {
        cout<<Rand7()<<endl;
        sleep(1);
    }
    return 0;
}

/*
class Solution {
public:
    bool IsValidOfRowCol(vector<vector<char>>& board,int index,bool IsRowOfCol = true)
    {
        unordered_map<char,int> num_map = {{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},
                                          {'6',1},{'7',1},{'8',1},{'9',1}};
        if(IsRowOfCol)
        {
            for(int i = 0;i < board.size();i++)
            {
                if(0 == num_map[board[index][i]] && board[index][i] != '.')
                {
                    return false;
                }
                num_map[board[index][i]]--;
            }
        }
        else 
        {
            for(int i = 0;i < board.size();i++)
            {
                if(0 == num_map[board[i][index]] && board[i][index] != '.')
                {
                    return false;
                }
                num_map[board[i][index]]--;
            }
        }

        return true;
    }

    bool IsValidOfThree(vector<vector<char>>& board,int x,int y)
    {
        unordered_map<char,int> num_map = {{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},
                                          {'6',1},{'7',1},{'8',1},{'9',1}};
        for(int i = x;i < x + 3;i++)
        {
            for(int j = y;j < y + 3;j++)
            {
                if(0 == num_map[board[i][j]] && board[i][j] != '.')
                {
                    return false;
                }

                num_map[board[i][j]]--;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty() || board.size() != 9 || board[0].size() != 9)
        {
            return false;
        }

        for(int i = 0;i < board.size();i++)
        {
            if(IsValidOfRowCol(board,i,true) == false)
            {
                return false;
            }

            if(IsValidOfRowCol(board,i,false) == false)
            {
                return false;
            }
        }

        for(int i = 0;i < board.size();i += 3)
        {
            for(int j = 0;j < board.size();j += 3)
            {
                if(IsValidOfThree(board,i,j) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
        int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
        int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
        for(int i=0; i<9; i++){
            for(int j = 0; j<9; j++){
                // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
                // 同时判断这个数在其所在的列有没有出现过
                // 同时判断这个数在其所在的box中有没有出现过
                if(board[i][j] == '.') continue;
                int curNumber = board[i][j]-'0';
                if(row[i][curNumber]) return false; 
                if(col[j][curNumber]) return false;
                if(box[j/3 + (i/3)*3][curNumber]) return false;

                row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
                col[j][curNumber] = 1;
                box[j/3 + (i/3)*3][curNumber] = 1;
            }
        }
        return true;
    }
};

