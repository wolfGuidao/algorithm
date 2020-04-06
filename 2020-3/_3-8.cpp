#include "Header.hpp"
using namespace std;

//组合
//1.先固定一个，再去递归选择后面的（后面也一样，固定一个）
//2.直到最后一个选择后，再撤销刚才的选择，取选择其他的
//3.一步一步往前回退，把每一位都进行撤销去选择其他的
vector<vector<int>> ret;
vector<int> track;

void backtrack(int n,size_t k,int start,vector<int>& track)
{
  if(track.size() == k)
  {
    ret.push_back(track);
  }

  for(int i = start;i <= n;i++)
  {
    track.push_back(i);
    backtrack(n,k,i + 1,track);
    track.pop_back();
  }
}

int main()
{
  int n = 5;
  int k = 2;
  int start = 1;
  backtrack(n,k,start,track); 
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
