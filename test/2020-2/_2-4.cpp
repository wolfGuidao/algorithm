#include "Header.hpp"

//高精度加法

string Add(const string& str1,const string& str2)
{
  if(str1.empty() || str2.empty())
  {
    return " ";
  }

  string ret;
  int str1_len = str1.size();
  int str2_len = str2.size();
  int i = str1_len - 1;
  int j = str2_len - 1;
  int index = 0;
  while(i >= 0 || j >= 0)
  {
    int left;
    int right;
    if(i < 0)
    {
      left = 0; 
    }
    else 
    {
      left = str1[i] - '0';
      i--;
    }
    if(j < 0)
    {
      right = 0;
    }
    else 
    {
      right = str2[j] - '0'; 
      j--;
    }
    int add = left + right + index;
    index = 0;
    if(add >= 10) 
    {
      ret += to_string(add % 10);
      index = add / 10;
    }
    else 
    {
      ret += to_string(add);
    }
  }
  if(index)
  {
    ret += to_string(index);
  }
  reverse(ret.begin(),ret.end());
  return ret;
}

int main()
{
  string str1;
  string str2;
  getline(cin,str1);
  getline(cin,str2);
  cout<<str1<< " + "<<str2<<" = "<<Add(str1,str2)<<endl;
  return 0;
}
