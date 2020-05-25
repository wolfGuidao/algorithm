#include "Header.hpp"

vector<vector<int>> subsets(vector<int>& nums) {
  // base case，返回一个空集
  if (nums.empty()) 
    return {{}};

  // 把最后一个元素拿出来
  int n = nums.back();
  nums.pop_back();

  // 先递归算出前面元素的所有子集
  vector<vector<int>> res = subsets(nums);

  int size = res.size();
  for (int i = 0; i < size; i++) 
  {
    // 然后在之前的结果之上追加
    res.push_back(res[i]);

    //在每个结果后面push一个前面保存的元素n
    res.back().push_back(n);
    //eg:{1,2} : {},{1},{2},{1,2} 
    //n = 2  res = subsets()
    //     n = 1    res = sunsets()
    //              res = { {} }
    //	   i = 0; i < 1;i ++
    //     res = { {}, {} }
    //	   res = { {},{1} }
    //i = 0;i < 2;i ++
    //res = { {},{1},{} }
    //res = { {},{1},{2} }
    //res = { {},{1},{2},{1} }
    //res = { {},{1},{2},{1,2} }
  }

  return res;
}

