/*************************************************************************
# File Name: 8-13.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月29日 星期三 14时18分30秒
*************************************************************************/
#include <iostream>
using namespace std;

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


