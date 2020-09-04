/*************************************************************************
# File Name: 9-1.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月04日 星期五 09时25分53秒
 *************************************************************************/
#include <iostream>
using namespace std;

class A 
{
    public:
        void Print()
        {
            cout<<a<<endl;
        }

        static int a;
};

int A::a = 999;

int main()
{
    A a;
    a.Print();
    return 0;
}
