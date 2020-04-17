#include "Header.hpp"

namespace wolf 
{
  class string 
  {
    public:
      string(const char* str = "")
      {
        cout<<"i am 构造"<<endl;
        if(str == nullptr)
        {
          _str = "";
        }
        _str = (char*)malloc(strlen(str)+ 1);
        strcpy(_str,str);
      }

      string(const string& s)
      {
        cout<<"i am 拷贝"<<endl;
        char* temp = (char*)malloc(strlen(s._str) + 1);
        strcpy(temp,s._str);
        _str = temp;
        temp = nullptr;
      }

      string(string&& s)
      {
        cout<<"i am 移动构造"<<endl;
        swap(s._str,_str);
        s._str = nullptr;
      }

      string operator=(const string& s)
      {
        cout<<"i am 赋值"<<endl;
        if(&s != this)
        {
          char* temp = (char*)malloc(strlen(s._str) + 1);
          strcpy(temp,s._str);
          free(_str);
          _str = temp;
        }
        return *this;
      }

      string operator=(string&& s)
      {
        cout<<"i am 移动赋值"<<endl;
        if(&s != this)
        {
          swap(s._str,_str);
          s._str = nullptr;
        }
        return *this;
      }

      ~string()
      {
        if(_str != nullptr)
        {
          free(_str);
        }
      }

      string operator+(const string s)
      {
        char* temp = (char*)malloc(strlen(s._str) + 1 + strlen(_str));
        strcpy(temp,_str);
        strcpy(temp + strlen(_str),s._str);
        string ret(temp);
        return ret;
      }
      friend ostream& operator<< (ostream& _cout,const string& s)
      {
        _cout<<s._str;
        return _cout;
      }
      friend istream& operator>> (istream& _cin, string& s)
      {
        _cin>>s._str;
        return _cin;
      }
    private:
      char* _str;
  };
};

void Fun(int &){cout << "lvalue ref" << endl;}
void Fun(int &&){cout << "rvalue ref" << endl;}
void Fun(const int &){cout << "const lvalue ref" << endl;}
void Fun(const int &&){cout << "const rvalue ref" << endl;}

template<typename T>
void PerfectForward(T &&t)
{
  //Fun(std::forward<T>(t));
  Fun(t);
}

int main()
{
  PerfectForward(10); // rvalue ref
  int a;
  PerfectForward(a); // lvalue ref
  PerfectForward(std::move(a)); // rvalue ref
  const int b = 8;
  PerfectForward(b); // const lvalue ref
  PerfectForward(std::move(b)); // const rvalue ref
  return 0;

}

