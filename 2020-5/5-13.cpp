#include "Header.hpp"

//vector<vector<int>> subsets(vector<int>& nums) 
//{
//  vector<vector<int>> res ;
//  res.push_back({});//先放一个空集
//
//  for (auto n : nums) //遍历nums
//  {
//    int size = res.size();
//    for (int i = 0; i < size; i++) 
//    {
//      vector<int> newSub = res[i];
//      newSub.push_back(n);
//      res.push_back(newSub);
//    }
//  }
//  return res;
//
//
//}

//vector<vector<int>> subsets(vector<int> nums)
//{
//  vector<vector<int>> ret;
//  if(nums.empty())
//  {
//    ret.push_back({});
//  }
//  else 
//  {
//    int val = nums.back();
//    nums.pop_back();
//    ret = subsets(nums);
//    size_t size = ret.size();
//    for(size_t i = 0;i < size;i++)
//    {
//       ret.push_back(ret[i]);
//       ret.back().push_back(val);
//    }
//  }
//  return ret;
//}

int main()
{
  vector<int> v {1, 2, 3, 4};
  vector<vector<int>> ret = subsets(v);
  for(auto e : ret)
  {
    for(auto m : e)
    {
      cout<<m<<" ";
    }
    cout<<endl;
  }
  return 0;
}
