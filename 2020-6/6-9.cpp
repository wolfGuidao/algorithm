/*************************************************************************
  > File Name: 6-9.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月30日 星期六 17时49分50秒
 ************************************************************************/

#include "Header.hpp"


int main() 
{
  int n;
  cin >> n;

  while (n--) 
  {
    int state = 0;//代表状态机🐔的3种状态，初始化为状态0，处理任意型字符
    char cur;//代表当前待判断的字符，
    string str;//目标字符串
    cin >> str;

    char last = str[0];//初始化为第一个字符
    string ans = "";//保存结果集
    ans += str[0];//初始化

    for (int i = 1; i < str.size(); ++i) 
    {
      //开始判断
      cur = str[i];

      switch (state)
      {
        case 0:
          {
            if (cur == last)//如果当前字符和上一个字符是相等的，进入状态
              //1，因为可能出现AAA的情况，否则是肯定出会出现，继续在状态0；
              state = 1;    //进入状态1：AA形式
            else 
              state = 0; //继续状态0：AB形式，即正常形式
            break;
          }

        case 1:
          {
            if (cur == last)
              continue;//AAA,忽略即可，不加入结果集
            else
              state = 2;//进入状态3：AAB形式，因为可能出现AABB的情况
            break;
          }

        case 2:
          {
            if (cur == last)
              continue;//AABB，忽略即可，不加入结果集
            else
              state = 0;//AABC，就是状态0，因为不可能出现AAA或AABB的情况
            break;
          }

        default:
          break;
      }

      //加入结果集
      ans = ans + cur;
      //更新上一个元素
      last = cur;
    }
    cout << ans << endl;
  }
  return 0;
}


