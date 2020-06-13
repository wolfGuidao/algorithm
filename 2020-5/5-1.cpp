#include "Header.hpp"

void Func()
{
  int a = 1;
  int b = 0;
  
  if(b == 0)
  {
    throw "error";
  }
  else 
  {
    cout<<a / b<<endl;
  }
  cout<<"i am in func"<<endl;
}

int main()
{
  try 
  {
    Func();
    cout<<"i am func end"<<endl;
  }
  catch (...)
  {
    cout<<"error"<<endl;
  }
  cout<<"i am main end"<<endl;
  return 0;
}
