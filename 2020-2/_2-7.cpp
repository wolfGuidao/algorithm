#include "Header.hpp"

void Reverse(char* str,int size)
{
  if(size > 0)
  {
    swap(*str,*(str + size - 1));
    Reverse(str+ 1,size - 2);
  }
  return ;
  
}

int main()
{
  char str[6] = "hello";
  int n = 5;
  Reverse(str,n);
  cout<<str<<endl;
  return 0;
}
