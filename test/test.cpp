#include "Header.hpp

#if 0
class A
{
  public:
    A()
    {
      cout<<"i am A()"<<endl;
    }
    ~A()
    {
      cout<<"i am ~A()"<<endl;
    }
};

void Test()
{
  //shared_ptr<A> sp(new A());
  A* a = new A();
  shared_ptr<A> ss(a);
}

int main()
{
  Test();
  return 0;
}
#endif

#if 0
class Node
{
  public:
    Node()
      //:prev(nullptr)
      // ,next(nullptr)
  {}
    ~Node()
    {
      cout<<"i am ~Node()"<<endl;
    }

  //private:
   //shared_ptr<Node> prev;
   //shared_ptr<Node> next;
   weak_ptr<Node> prev;
   weak_ptr<Node> next;
};

void Test()
{
  shared_ptr<Node> str1(new Node);
  shared_ptr<Node> str2(new Node);
  str1->next = str2;
  str2->prev = str1;
  cout<<"str1: "<<str1.use_count()<<endl;
  cout<<"str2: "<<str2.use_count()<<endl;
}
int main()
{
  Test();
  return 0;
}
#endif

#if 0
int main()
{

  map<int,int>mp;
  mp[0]++;
  mp[1]++;
  mp[2]++;
  mp[3]++;
  mp[4]++;
  auto it = mp.begin();
  it += 8;
  cout<<it->first<<endl;
  return 0;
}

#endif 

#if 0
#include "httplib.h"
int main()
{
  using namespace httplib;
  Server ser;
  ser.Get("/a",[](const Request& req,Response& res)
      {
        cout<<"i am test"<<endl;
        //res.set_content("1","test/html;charset=UTF-8");
      });

  ser.listen("0.0.0.0",9090);
  return 0;
}
#endif 

#if 0
class A
{
  public:
    virtual void Print()
    {
      cout<<"i am A()"<<endl;
    }
  private:
};

class B : public A 
{
  public:
    void Print()
    {
      cout<<"i am B()"<<endl;
    }
};

void Test(A* a)
{
  a->Print();
}


int main()
{
  A a;
  B b;
  Test(&a);
  Test(&b);
  return 0;
lass A
{
  public:
    virtual void Print()
    {
      cout<<"i am A()"<<endl;
    }
  private:
};

class B : public A 
{
  public:
    void Print()
    {
      cout<<"i am B()"<<endl;
    }
};

void Test(A* a)
{
  a->Print();
}


int main()
{
  A a;
  B b;
  Test(&a);
  Test(&b);
  return 0;
}
#endif

int main()
{
  char str[] = "hello";
  cout<<"sizeof : "<<sizeof(str)<<" strlen: "<<strlen(str)<<endl;
  return 0;
}
