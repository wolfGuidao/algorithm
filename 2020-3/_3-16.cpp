#include "Header.hpp"
using namespace std;

//
//有 N 堆金币排成一排，第 i 堆中有 C[i] 块金币。每次合并都会将相邻的两堆金币合并为一堆，成本为这两堆金币块数之和。经过N-1次合并，最终将所有金币合并为一堆。请找出将金币合并为一堆的最低成本。
//3 2 4 1 : 20 
//3 + 2 = 5; 1 + 4 = 5; 5 + 5 = 10;所以最后耗费的体力为：5 + 5 + 10 = 20

int main()
{
  using namespace std;
  std::string str1 = "9";
  std::string str2 = "123";

  if(str1 > str2)
  {
    cout<<"str1 : "<<str1<<endl; 
  }
  else 
  {
    cout<<"str2 : "<<str2<<endl;
  }

  return 0;
}
