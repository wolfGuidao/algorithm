/*************************************************************************
  > File Name: 6-24.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月12日 星期五 16时00分46秒
 ************************************************************************/

#include "Header.hpp"

//typedef unsigned int (*fun)(unsigned int);
//
//unsigned int func1(unsigned int)
//{
//  return 0;
//}
//
//unsigned int func2(unsigned int n)
//{
//  static fun arr[2] = {func1, func2};
//  return arr[!!n](n - 1) + n;
//}

//template<unsigned int n>
//struct func1 
//{
//    enum Value
//    {
//        N = func1<n - 1>::N + n,
//    };
//};
//
//template<>
//struct func1<1>
//{
//    enum Value 
//    {
//        N = 1,
//    };
//};

enum Value 
{
    value1 = 0,
    value2,
    value3
};


int main()
{
    cout<<value1<<endl;
    return 0;
}

