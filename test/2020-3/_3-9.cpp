#include "Header.hpp"

int GetMoney(vector<int>& arr,int start,int end)
{

  int dp_1 = 0;
  int dp_2 = 0;
  
  int dp_i = 0;

  for(int i = end;i >= start;i--)
  {
    dp_i = max(dp_1,arr[i] + dp_2);
    dp_2 = dp_1;
    dp_1 = dp_i;
  }
  return dp_i;
}

int main()
{
  vector<int> arr = {1,2,3,1};
  if(arr.size() == 1)
  {
    return arr[0];
  }
  cout<<max(GetMoney(arr,0,arr.size() - 2),GetMoney(arr,1,arr.size() - 1))<<endl;
}
