/*************************************************************************
# File Name: 8-7.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月22日 星期三 18时29分31秒
 *************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void Print(vector<vector<int>>& arr,int n)
{
    for(int level = 0;level < 2 * n - 1;level++)
    {
        int sum = level;
        for(int i = 0;i < n;i++)
        {
            int j = sum - i;
            if(i >= 0 && i < n && j >= 0 && j < n)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void printMatrix(vector<vector<int>>matrix,int n)
{
    for(int level = 0;level < 2 * n - 1;level++)
    {
        int diff = n - level - 1;
        for(int j = 0;j < n;j++)
        {
            int i = j - diff;
            if(i >= 0 && i < n && j >= 0 && j < n)
            {
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> arr {{1,2,3},{4,5,6},{7,8,9}};
    Print(arr,3);
    printMatrix(arr,3);
    return 0;
}

