/*************************************************************************
# File Name: 9-23.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月28日 星期一 13时01分03秒
*************************************************************************/
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    for(int i = 0;i < 2;i++)
    {
        //printf("@\n");
        printf("@");
        fork();
    }
    return 0;
}
