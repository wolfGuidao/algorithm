/*************************************************************************
# File Name: 9-21.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月27日 星期日 18时47分02秒
*************************************************************************/
#include <iostream>
using namespace std;

#if 0
static int a = 999;

int main()
{
    cout<<"&a-> "<<&a<<endl;
    static int a = 666;
    cout<<a<<endl;
    cout<<"&a-> "<<&a<<endl;
    return 0;
}
#endif 

class Test;

Test* ss;

class Test 
{
    public:
        static void Print(Test* a)
        {
            cout<<"i am Print()"<<endl;
            cout<<"i am static : "<<test_static<<endl;
            cout<<"i am no static : "<<a->test_no_static<<endl;
            cout<<"i am no static : "<<ss->test_no_static<<endl;
        }
    private:
        static int test_static;
        int test_no_static = 666;
};

int Test::test_static = 999;


int main()
{
    Test a;
    Test::Print(&a);
    return 0;
}
