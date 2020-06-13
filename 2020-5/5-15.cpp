#include "Header.hpp"

unsigned char i;
int main()
{
  //char a= -1;
  //signed char b=-1;
  //unsigned char c=-1;
  //printf("a=%d,b=%d,c=%d",a,b,c);
  //char a = -128;
  //printf("%u\n",a);
  //char a[1000];
  //int i;
  //for(i=0; i<1000; i++)
  //{
  //  a[i] = -1-i;
  //}
  //printf("%d",strlen(a));
  //int count = 0;
  //for(i = 0;i<=255;i++)
  //{
  //  count++;
  //  //printf("hello world\n");
  //}
  //cout<<count<<endl;

  char str1[] = "hello bit.";
  char str2[] = "hello bit.";
  char *str3 = "hello bit.";
  char *str4 = "hello bit.";
  if(str1 ==str2)
    printf("str1 and str2 are same\n");
  else
    printf("str1 and str2 are not same\n");
  if(str3 ==str4)
    printf("str3 and str4 are same\n");
  else
    printf("str3 and str4 are not same\n");
  return 0;

}
