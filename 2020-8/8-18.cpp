/*************************************************************************
# File Name: 8-18.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月16日 星期日 15时25分34秒
*************************************************************************/
#include <iostream>
using namespace std;

class A 
{
    public:
        ~A()
        {
            cout<<"~A()"<<endl;
        }
};

int main()
{
    A* p = nullptr;
    p = new A[4];
    delete p;
    return 0;
}
