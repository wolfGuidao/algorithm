#include "Header.hpp"

#if 0
void Func1()
{
  throw string("i am text throw");
}

void Func2()
{
  try
  {
    Func1();
  }
  catch(int)
  {
    cout<<" i am Func2(),catch int"<<endl;
  }
  catch(...) 
  {
    cout<<"i am Func2() i catch a err "<<endl;
  }
}

void Func3()
{
  try 
  {
    Func2();
  }
  catch(...) 
  {
    printf("i am catch a err\n");
  }
}

void Func1()
{
  throw "i am error";
}

void Func2()
{
  try 
  {
    Func1();
  }
  catch(int)
  {
    cout<<"i am int"<<endl;
  }
  catch(const string) 
  {
    cout<<"i am const string"<<endl;
  }
  catch(string)
  {
    cout<<"i am string"<<endl;
  }
  catch(char*) 
  {
    cout<<"i am char*"<<endl;
  }

}
#endif

void Func1()
{
  cout<<"i am Func1() throw befor"<<endl;
  throw 999;
  cout<<"i am Func1() throw after"<<endl;
}

void Func2()
{
  try 
  {
    cout<<"i am Func2() try befor"<<endl;
    Func1();
    cout<<"i am Func2() try after"<<endl;
  }
  catch(int)
  {
    cout<<"i am Func2() catch befor"<<endl;
    throw ;
    cout<<"i am Func2() catch after"<<endl;
  }
}

void Func3()
{
  try 
  {
    cout<<"i am Func3() try befor"<<endl;
    Func2();
    cout<<"i am Func3() try after"<<endl;
  }
  catch(string)
  {
    cout<<"i am string"<<endl;
  }
  catch(...)
  {
    cout<<"i am Func3() catch befor"<<endl;
    cout<<"i catch a error"<<endl;
    cout<<"i am Func3() catch after"<<endl;
  }
  cout<<"i am func3() end"<<endl;
}

int main()
{
  Func3();
  return 0;
}
