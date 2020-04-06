#include "Header.hpp"
using namespace std;

//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串（回文串是一个正读和反读都一样的字符串）。
//
//具有不同开始位置或结束位置的回文串，即使是由相同的字符组成，也会被计为是不同的子串。
//aaa : 6
//aabaa : 9

int Count(std::string& str)
{
  //计数
  int count = 1;

  //每次从第二的字符开始
  for(size_t i = 1;i < str.size();i++)
  {
    //每次循环都要置为空串，相当于每次以i位置为终点，找回文串
    string x = "";
    //把i位置处的字符保存
    x += str[i];
    //j从1开始，直到和i相等的位置，
    for(size_t j = 1;j <= i;j++)
    {
      //随着j的增加，x获得的字符是从i - 1，i - 2....0构成的字符串
      x += str[i - j];
      string temp = x;
      reverse(temp.begin(),temp.end());
      //如果相等就是一个回文
      if(x == temp)
      {
        count++;
      }
    }
    //单个字符也是回文
    count++;
  }
  return count;
}

int main()
{
  string str;
  cin>>str;
  cout<<Count(str)<<endl;
  return 0;
}
