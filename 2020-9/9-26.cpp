/*************************************************************************
# File Name: 9-26.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年10月08日 星期四 16时57分20秒
*************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a = 999;
    int& pa = a;
    cout<<"a: "<<&a<<" pa: "<<&pa<<endl;
    return 0;
}
