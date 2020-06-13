/*************************************************************************
  > File Name: 6-3.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月28日 星期四 16时36分01秒
 ************************************************************************/

#include "Header.hpp"

class A 
{}; 
class B : virtual public A
{};
class C : virtual public A
{};
class D : public B , public C
{};

void Func1()
{
  cout<<sizeof(D)<<endl;
}

class E 
{
  virtual void test1()
  {}
};

class F 
{
  virtual void test2()
  {}
};

class G : public E, public F
{

};

void Func2()
{
  cout<<sizeof(G)<<endl;
}

static int b;
void Func3()
{
  static int a;
  cout<<a<<endl;
  cout<<b<<endl;
}

void Func4()
{
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  map<int,int> mp = {{1,1},{2,2},{3,3},{4,4}};

  auto it = mp.begin();
  while(!mp.empty())
  {
    auto nit = it++;
    mp.erase(nit);
    //cout<<it->first<<" ";
  }

  for(auto e : mp)
  {
    cout<<e.first<<" ";
  }
  cout<<endl;
}

int main()
{
  //Func1(); 
  //Func2();
  //Func3();
  Func4();
  return 0;
}

