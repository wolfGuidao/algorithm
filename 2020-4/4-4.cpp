#include "Header.hpp"

//算法训练 s01串
//时间限制：1.0s 内存限制：256.0MB
//
//问题描述
//　　s01串初始为"0"
//　　按以下方式变换
//　　0变1，1变01
//输入格式
//　　1个整数(0~19)
//  输出格式
//  　　n次变换后s01串
//  样例输入
//  3
//  样例输出
//  101
//  数据规模和约定
//  　　0~19
//

string S01(int n)
{
  if(n == 0)
  {
    return to_string(0);
  }
  if(n == 1)
  {
    return to_string(1);
  }
  return S01(n - 1) + S01(n - 2);
}

int main()
{
  int n = 3;
  cout<<S01(n)<<endl;
}
