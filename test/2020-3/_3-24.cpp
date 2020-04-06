#include "Header.hpp"

int dp(const string& str1,const string& str2,int i,int j)
{
  if(i < 0 || j < 0)
  {
    return 0;
  }

  if(str1[i] == str2[j])
  {
   return dp(str1,str2,i - 1,j - 1) + 1; 
  }
  else 
  {
    return max(dp(str1,str2,i - 1,j),dp(str1,str2,i,j - 1));
  }

}

int main()
{
  cout<<dp("abcde","xyz",4,2)<<endl;
  return 0;
}
