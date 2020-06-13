#include "Header.hpp"

void* GetInt()
{
  return new int(99);
}

int main()
{
  //short a = 30000;
  //short b = 30000;
  //decltype(a + b) c = a + b;
  ////测试typeid
  //cout<<typeid(c).name()<<endl;
  //cout<<c<<endl;
  //cout<<typeid(GetInt).name()<<endl;
  //cout<<typeid(GetInt()).name()<<endl;
  string str1 = "hello";
  string str2(std::move(str1));
  //cout<<str1<<" "<<str2<<endl;
  cout<<str1<<endl;

  return 0;
}
