/*************************************************************************
  > File Name: 7-17.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月03日 星期五 13时38分53秒
 ************************************************************************/

#include "Header.hpp"

#include<stdio.h>  
#include<stdarg.h>  
int getMax(int n, ...)  
{  
    va_list va;  
    va_start(va,n); // init va, pointing to the first argument  
    int smax = -1;  

    for(int i = 0;i < n;i++)  
    {  
        int tmp = va_arg(va,int); // get the next argument, the type is int  
        if(tmp > smax) 
            smax = tmp;  
    }  
    va_end(va);  
    return smax;  
}  

int main()  
{  
    printf("%d\n",getMax(4,9,5,2,19));  
    printf("%d\n",getMax(7,1,3,4,5,2,0,999));  
}  

