/*
 *小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？ 

 输入描述:
 输入第一行包含一个字符串s，代表压缩后的字符串。
 S的长度<=1000;
 S仅包含大写字母、[、]、|;
 解压后的字符串长度不超过100000;
 压缩递归层数不超过10层;

 输出描述:
 输出一个字符串，代表解压后的字符串。

 输入例子1:
 HG[3|B[2|CA]]F

 输出例子1:
 HGBCACABCACABCACAF

 例子说明1:
 HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
 * */
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <stack>
using namespace std;
int main()
{
  string str;
  stack<char> s;
  getline(cin,str);
  for(auto e : str)
  {
    if(e != ']')
    {
      s.push(e);

    }
    else 
    {
      string temp;
      while(s.top() != '[')
      {
        temp += s.top();
        s.pop();

      }
      s.pop();
      reverse(temp.begin(),temp.end());
      int num = stoi(temp.substr(0,temp.find('|')));
      string chs = temp.substr(temp.find('|') + 1);

      while(num)
      {
        for(auto m : chs)
        {
          s.push(m);

        }
        num--;

      }
    }
  }
  string ss;
  while(!s.empty())
  {
    ss += s.top();
    s.pop();

  }
  reverse(ss.begin(),ss.end());
  for(auto e : ss)
  {
    cout<<e;

  }
  return 0;
}
