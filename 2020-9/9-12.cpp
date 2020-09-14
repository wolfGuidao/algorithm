/*************************************************************************
# File Name: 9-12.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月14日 星期一 15时30分07秒
*************************************************************************/

#include <iostream>
using namespace std;

struct str 
{
    char ch;
    union tmp 
    {
        int a;
    }aa;
};

int main()
{
    char arr[] = {'a','b','c','d','e'};
    printf("%s\n",arr);

    int arr1[6] = {1,2,3,4,5,6};
    int i = 0;
    cout<<sizeof(arr1[++i])<<" : "<<i<<endl;

    int register temp = 999;
    cout<<temp<<endl;


    cout<<sizeof(struct str)<<endl;
    return 0;
}
