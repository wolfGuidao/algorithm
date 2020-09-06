/*************************************************************************
# File Name: 9-6.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月06日 星期日 10时36分50秒
*************************************************************************/
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <limits.h>
using namespace std;

int Rand7()
{
    return rand() % 7 + 1;
}


int Rand10()
{
    int num = INT_MAX;
    while(num > 10)
    {
        num = 7 * (Rand7() - 1) + Rand7();
    }

    return num;
}

int main()
{
    srand((unsigned)time(nullptr));
    while(1)
    {
        cout<<Rand10()<<endl;
        sleep(1);
    }
    return 0;
}
