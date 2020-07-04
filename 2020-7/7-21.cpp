/*************************************************************************
  > File Name: 7-21.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月03日 星期五 18时03分47秒
 ************************************************************************/

#include "Header.hpp"

#if 0
class A 
{
    public:
        static void Print()
        {
            cout<<"i am static mothed"<<endl;
            _ptr.val += 1000;
            cout<<_ptr->val;
        }

        A()
        {
            _ptr = this;
            val = 999;
        }

        static A* _ptr;
        int val;
};

int main()
{
    A a;
    a.Print();
    A::Print();
    return 0;
}

#endif 

#if 0
class A
{
    public:
        A()
        {
            m_gA = this;
        }

        static void test()
        {
            m_gA->m_a += 1;
            cout<<m_gA->m_a<<endl;
        }
        void hello()
        {
        }
    private:
        static int m_staticA;
        static A *m_gA;
        int m_a = 999;
};
#endif 

class A
{

    public:
        A()
            :a(1)
             ,b(2)
        {
            
        }
        static int GetC()
        {
            c += 1000;
            return c;
        }
        int a;
        int b;
        static int c;
};
int A::c = 999;

int main()
{
    //A::test();
    A a;
    cout<<a.GetC()<<endl;
    cout<<A::GetC()<<endl;
    return 0;
}
