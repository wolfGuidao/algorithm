/*************************************************************************
  > File Name: 6-8.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月30日 星期六 17时31分49秒
 ************************************************************************/

#include "Header.hpp"

//25 * 25 * 25 + 25 * 25 + 25 + 1
//25 * 25 + 25 + 1
//25 + 1
//1
const int arr[] = {16276, 651, 26, 1};

int main()
{
  string s;
  cin>>s;

  int ans = 0;

  for(size_t i = 0; i < s.length(); i++)
  {
    int if_1 = 1;
    if(i == 0) 
      if_1 = 0;

    ans += (s[i]-'a') * arr[i] + if_1;
  }
  printf("%d\n", ans);
  return 0;
}
