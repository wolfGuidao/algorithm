/*************************************************************************
    > File Name: 6-18.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月05日 星期五 22时32分46秒
 ************************************************************************/

#include "Header.hpp"

int main()
{
    string str = "hello world i am wolf";
    size_t len = str.size();
    for(size_t i = 0;i < len;i++)
    {
      if(str[i] == ' ')
      {
        str.replace(i,0,"%20");
        i += 2;
      }
    }
    cout<<str<<endl;
    return 0;
}

