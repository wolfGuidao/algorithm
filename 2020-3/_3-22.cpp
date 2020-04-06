#include "Header.hpp"

int min(int a,int b,int c)
{
  return min(a,min(b,c));
}

int dp(string& str1,string& str2,int i,int j)
{
  if(i < 0)
  {
    return j + 1;
  }

  if(j < 0)
  {
    return i + 1;
  }
  
  int Min = INT_MAX;
  if(str1[i] == str2[j])
  {
    return dp(str1,str2,i - 1,j - 1);
  }
  else 
  {
    Min = min(dp(str1,str2,i - 1,j - 1) + 1,
              dp(str1,str2,i,j - 1) + 1,
              dp(str1,str2,i - 1,j) + 1); 
  }
  
  return Min;
}

void minDestence(string str1,string str2)
{
  if(str1.empty())
  {
    cout<< str2.size()<<endl;
  }
  if(str2.empty())
  {
    cout<< str1.size()<<endl;
  }
  cout<<dp(str1,str2,str1.size() - 1,str2.size() - 1)<<endl;;
}

int main()
{
  minDestence("abc","abcdef");
  return 0;
}
