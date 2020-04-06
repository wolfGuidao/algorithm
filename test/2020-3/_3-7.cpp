#include "Header.hpp"

vector<vector<int>> ret;
vector<int> track;

//排列
bool IsTrue(vector<int>& arr,int val)
{
  for(auto e : arr)
  {
    if(e == val)
    {
      return false;
    }
  }
  return true;
}

void backtrack(vector<int>& arr,vector<int>& track)
{
  if(track.size() == arr.size())
  {
    ret.push_back(track);
    return ;
  }

  for(size_t i = 0;i < arr.size();i++)
  {
    if(IsTrue(track,arr[i]))
    {
      track.push_back(arr[i]);
    }
    else 
    {
      continue;
    }

    backtrack(arr,track);
    track.pop_back();
  }
}

int main()
{
  vector<int> arr = {1,2,3,4,5};
  backtrack(arr,track);
  for(auto e : ret)
  {
    cout<<"[";
    for(auto m : e)
    {
      cout<<m<<",";
    }
    cout<<"]"<<endl;
  }
  return 0;
}
