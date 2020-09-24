/*************************************************************************
# File Name: 9-18.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月24日 星期四 14时35分20秒
*************************************************************************/
#include <iostream>
using namespace std;

class TestString 
{
    public:
        explicit TestString(int size)
        {
            _size = size;
            _str = nullptr;
        }

        TestString(char* str)
        {
            _size = 66;
            _str = str;
        }

        size_t GetSize()
        {
            return _size;
        }

        char* GetStr()
        {
            return _str;
        }

    private:
        size_t _size;
        char* _str;
};

int main()
{
    TestString a(10);
    cout<<a.GetSize()<<endl;
    TestString b = 99;
    cout<<b.GetSize()<<endl;
    TestString c("abcd");
    cout<<c.GetStr()<<endl;
    TestString d = "defg";
    cout<<d.GetStr()<<endl;
    return 0;
}
