/*************************************************************************
  > File Name: 6-31.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月18日 星期四 12时07分27秒
 ************************************************************************/

#include "Header.hpp"
#if 0
static int a = 999;

int aa;
extern int flag;
extern void Print();
int main()
{
    //const char str[] = "hello\0wollf";
    //char str[] = "\0";
    //char str[] = "wolf\0222222";
    //cout<<sizeof(str)<<endl;
    //cout<<strlen(str)<<endl;
    //static int a = 888;
    //cout<<a<<endl;
    //cout<<flag<<endl; 
    //Print();
    //int bb;
    //cout<<aa<<" : "<<bb<<endl;
    //deque<int> dp{1,2,3,4,5,6,7};
    //for(size_t i = 0;i < dp.size();i++)
    //{
    //    cout<<dp[i]<<endl;
    //}
    //deque<int>::iterator it = dp.begin();
    //while(it != dp.end())
    //{
    //    it = dp.erase(it);
    //}
    //for(size_t i = 0;i < dp.size();i++)
    //{
    //    cout<<dp[i]<<endl;
    //}
    //list<int> dp1{9,8,7,6,5,4};
    //list<int>::iterator it1 = dp1.begin();
    //while(it1 != dp1.end())
    //{
    //    cout<<*it1<<endl;
    //    it1++;
    //}

    //it1 = dp1.begin();
    //auto temp1 = it1;
    //while(it1 != dp1.end())
    //{
    //    temp1 = it1++;
    //    dp1.erase(temp1);

    //}

    //it1 = dp1.begin();
    //while(it1 != dp1.end())
    //{
    //    cout<<*it1<<endl;
    //    it1++;
    //}
    //string str = "wolf guidao";
    //auto it = str.begin();
    //cout<<str<<endl;
    //printf("%p\n",it);
    //while(it != str.end())
    //{
    //    printf("%p\n",it);
    //    it = str.erase(it);
    //    printf("%p\n",it);
    //    //it++;
    //}
    //cout<<str<<endl;
    int a = 0x12345678;
    char ch = *(char*)&a;
    if(ch == 0x78)
    {
        cout<<"小端"<<endl;
    }
    else 
    {
        cout<<"大端"<<endl;
    }
    return 0;
}
#endif

#if 0
typedef unsigned int uint_32 ;  
typedef unsigned short uint_16 ;  
#define BSWAP_32(x) \
    (uint_32)((((uint_32)(x) & 0xff000000) >> 24) | \
            (((uint_32)(x) & 0x00ff0000) >> 8) | \
            (((uint_32)(x) & 0x0000ff00) << 8) | \
            (((uint_32)(x) & 0x000000ff) << 24) \
            )  

int main()
{
    uint_32 a = 0x12345678;
    printf("%u\n",a);
    printf("%u\n",BSWAP_32(a));
    return 0;
}
#endif

#if 0
class C 
{};

class D : public C 
{};

class A 
{
    public:
        virtual void Print(int a = 1)
        {
            cout<<"A::a "<<a<<endl;
            cout<<__FILE__<<" : "<<__LINE__<<endl;
        }

        virtual C* Test()
        {
            cout<<"A::C* Test"<<endl;
            return new C;
        }
};

class B : public A 
{
    public:
        virtual void Print(int a = 2)
        {
            cout<<"B::a "<<a<<endl;
            cout<<__FILE__<<" : "<<__LINE__<<endl;
        }

        virtual D* Test()
        {
            cout<<"A::D* Test"<<endl;
            return new D;
        }

        void Add() const 
        {
            a++;
        }
        mutable  int a = 999;
        int c = 888;
};

class Compress 
{
    bool operator()(pair<int,int> left,pair<int,int> right)
    {
        return left.second > right.second;
    }
};

class Test 
{
    public:
        Test()
        {
            cout<<"test"<<endl;
        }
};

class Test1 : Test 
{
    public:
        Test1()
        {
            cout<<"test1"<<endl;
        }
};

int main()
{
    //A* a = new B;
    //a->Test();
    //map<int,int> mp{{1,2},{2,1},{3,6},{4,9}};
    //sort(mp.begin(),mp.end(),Compress());
    //auto it = mp.begin();
    //while(it != mp.end())
    //{
    //    cout<<it->second<<endl;
    //}
    //char str1[] = {'w','o','l','f'};
    //char str2[] = "wolf";
    //cout<<"str1: "<<sizeof(str1)<<" : "<<strlen(str1)<<endl;
    //cout<<"str2: "<<sizeof(str2)<<" : "<<strlen(str2)<<endl;
    //Test* test = (Test*)malloc(sizeof(Test));
    //test = new(Test)(999);
    Test1* test = (Test1*)new Test();
    return 0;
}
#endif

#if 0
int main()
{
    //const int a = 999;
    //int b = const_cast<int&> (a);
    //cout<<b<<endl;
    //auto_ptr<string> str(new string("hello wolf"));
    //string* str1 = new string("i ma test");
    //auto_ptr<string> str2(str1);
    //auto_ptr<string> str3(str);
    //cout<<*str3<<endl;
    //unique_ptr<int> arr1(new int(999));
    //unique_ptr<int> arr2(std::move(arr1));
    ////cout<<*arr1<<" : "<<*arr2<<endl;
    //cout<<*arr2<<endl;
    shared_ptr<int> arr1(new int(999));
    //shared_ptr<int> arr2(arr1);
    weak_ptr<int> arr2(arr1);
    shared_ptr<int> arr3 = arr1;
    arr2.lock();
    cout<<arr1.use_count()<<"："<<arr2.use_count()<<" : "<<arr3.use_count()<<endl;

    return 0;
}
#endif


#if 0
class B;
class A
{
    public:
        shared_ptr<B> pb_;
        ~A()
        {
            cout<<"A delete\n";
        }
        void Print()
        {
            cout<<"i am print()"<<endl;
        }
};
class B
{
    public:
        weak_ptr<A> pa_;
        ~B()
        {
            cout<<"B delete\n";
        }

        void Print()
        {
            cout<<"i am print()"<<endl;
        }
};
void fun()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa_ = pa;
    pa->pb_ = pb;
    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;
    pb->pa_.lock()->Print();
}
int main()
{
    //fun();
    //string str = "wolf-gui";
    //cout<<str.find('-')<<endl;
    //int pos = str.find('-');
    //string str1 = str.substr(0,pos);
    //cout<<str1<<endl;
    //string str2 = str.substr(pos + 1,str.size() - pos - 1);
    //cout<<str2<<endl;
    //const int a = 999;
    //int* pa = (int*)&a;
    //*pa = 666;
    //cout<<"a: "<<a<<" *pa: "<<*pa<<endl;
    //cout<<"&a: "<<&a<<" pa: "<<pa<<endl;
    //auto func1 = [](){};
    //auto func2 = [](){};
    //func2 = func1;
    //string str1 = "hello wolf";
    //string str2 = std::move(str1);
    //cout<<"str1: "<<str1<<endl;
    //cout<<"str2: "<<str2<<endl;
#include <array>
#include <forward_list>


    //array<int,3> arr {1,2,3};
    //for(size_t i = 0;i < arr.size();i++)
    //{
    //    cout<<arr[i]<<" ";
    //}
    forward_list<int> list{1,2,3};
    auto it = list.begin();
    while(it != list.end())
    {
        cout<<*it<<" ";
        it++;
    }

    std::list<int> llist{1,2,3};
    llist.remove(0);
    return 0;
}
#endif

#if 0
class A 
{
    public:
        A()
        {
            cout<<"i am construct"<<endl;
        }

        A(const A& )
        {
            cout<<"i am A(const A&)"<<endl;
        }

        A print(A a)
        {
            cout<<"i am print"<<endl;
            return a;
        }

};

int main()
{
    //A a;
    //A b;
    //a.print(b);
    int a = 999;
    int& b = a;
    int&& c = a + 1;
    cout<<&a<<" : "<<&b<<" : "<<&c<<endl;
    return 0;
}
#endif

#if 0
namespace wolf 
{
    class String
    {
        public:
            String(const char* str = "")
            {
                cout<<"const char* str"<<endl;
                if (nullptr == str)
                    str = "";
                //申请空间
                _str = new char[strlen(str) + 1];
                //拷贝元素
                strcpy(_str, str);
            }

            String(String&& s)
                : _str(s._str)
            {
                cout<<"String(string&&)"<<endl;
                s._str = nullptr;
            }


            String(const String& s)
                //申请空间
                : _str(new char[strlen(s._str) + 1])
            {
                cout<<"string(const string&)"<<endl;
                //拷贝元素
                strcpy(_str, s._str);
            }

            String operator=(String&& s)
            {
                if(&s != this)
                {
                    cout<<"operator=(string&&)"<<endl;
                    swap(_str,s._str);
                    s._str = nullptr;
                }
                return *this;
            }


            String& operator=(const String& s)
            {
                if (this != &s)
                {
                    cout<<"operator=(string&)"<<endl;
                    //申请空间
                    char* pTemp = new char[strlen(s._str) + 1];
                    //拷贝元素
                    strcpy(pTemp, s._str);
                    //释放旧空间
                    delete[] _str;
                    //指向新空间
                    _str = pTemp;
                }
                return *this;
            }

            String operator+(const String& s)
            {
                //申请大空间
                char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
                //拷贝元素
                strcpy(pTemp, _str);
                strcpy(pTemp + strlen(_str), s._str);
                //构造临时对象
                cout<<"operator+"<<endl;
                String strRet(pTemp);
                return strRet;
            }

            ~String()
            { 
                if (_str) delete[] _str;
            }
        private:
            char* _str;
    };
};

int main()
{
    wolf::String s1("hello");
    wolf::String s2("world");
    wolf::String s3(s2 + s1);
    return 0;
}
#endif

#if 0
void Fun(int &x)
{
    cout << "lvalue ref" << endl;
}

void Fun(int &&x)
{
    cout << "rvalue ref" << endl;
}

void Fun(const int &x)
{
    cout << "const lvalue ref" << endl;
}

void Fun(const int &&x)
{
    cout << "const rvalue ref" << endl;
}

    template<typename T>
void PerfectForward(T &&t)
{
    Fun(std::forward<T>(t));
}

int main()
{
    PerfectForward(10); // rvalue ref
    int a;
    PerfectForward(a); // lvalue ref
    PerfectForward(std::move(a)); // rvalue ref
    const int b = 8;
    PerfectForward(b); // const lvalue ref
    PerfectForward(std::move(b)); // const rvalue ref
    return 0;
}
#endif 

#include <iostream>
#include <thread>
#include <mutex>

//unsigned long sum = 0L;
//mutex m;
//
//void fun(size_t num)
//{
//    for (size_t i = 0; i < num; ++i)
//    {
//        m.lock();
//        sum++;
//        m.unlock();
//    }
//}

#if 0
#include <atomic>

atomic<int> sum{1};
void fun(size_t num)
{
    for(size_t i = 0;i < num;i++)
    {
        sum++;
    }
}

int main()
{
    cout << "Before joining,sum = " << sum << std::endl;
    thread t1(fun, 10000000);
    thread t2(fun, 10000000);
    t1.join();
    t2.join();
    cout << "After joining,sum = " << sum << std::endl;
    return 0;
}
#endif

#if 0
#include <bitset>
#include <bits/stdc++.h>

void func() throw(int,char*)
{
    ;
}

int main()
{
    //bitset<10> bs;
    //bs.set(1);
    //bs.set(2);
    //bs.set(3);
    //bs.set(4);
    //bs.set(5);

    try 
    {
        int b = 2;
        int c = 0;
        if(c == 0)
        {
            throw "by 0";
        }
        else 
        {
            int a = b / c;
            cout<<a<<endl;
        }
    }
    catch(char* str)
    {
        cout<<str<<endl;
    }
    catch(char * str)
    {
        cout<<str<<endl;
    }
    catch(...)
    {
        cout<<"false"<<endl;
    }
    return 0;
}
#endif


int main()
{
    char str[] = "hello0";
    cout<<strlen(str)<<endl;
    return 0;
}
