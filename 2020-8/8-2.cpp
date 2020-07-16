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
