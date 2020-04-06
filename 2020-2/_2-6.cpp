#include "Header.hpp"

//求幂集,不重复
//方法一：每次把最后一个元素往所有子集中push
vector<vector<int>> findsubsets(vector<int> arr)
{
  if(arr.empty())
  {
    return {{}};
  }

  int end = arr.back();
  arr.pop_back();
  vector<vector<int>> ret =  findsubsets(arr);

  //注意，此处必须要保存ret的大小，否则下面一直在插入就会造成死循环
  size_t size = ret.size();
  for(size_t i = 0;i < size;i++)
  {
    //每次把ret当中的每个元素拷贝一份放到ret的末尾
    ret.push_back(ret[i]);

    //再把刚刚拷贝的那份push一个之前保留的end元素
    ret.back().push_back(end);
  }
  return ret;
}
void subsets()
{
  vector<int> arr = {1,2,3};
  vector<vector<int>> ret = findsubsets(arr); 
  for(size_t i = 0;i < ret.size();i++)
  {
    cout<<"[";
    for(size_t j = 0;j < ret[i].size();j++)
    {
      cout<<ret[i][j]<<",";
    }
    cout<<"]"<<endl;
  }
}

//方法二：回溯
void dfs(vector<int> arr,vector<int>& track,vector<vector<int>>& ret,size_t index)
{
  //1.满足情况。如果track的值小于等于arr的size，就是子集，直接push
  ret.push_back(track);

  //循环遍历
  for(size_t i = index;i < arr.size();i++)
  {
    //2.做选择
    track.push_back(arr[i]);
    dfs(arr,track,ret,i + 1); 
    //3.撤销选择
    track.pop_back();
  }

}
void subsets1()
{
  vector<int> arr = {1,2,3};
  vector<vector<int>> ret;
  vector<int> track;
  dfs(arr,track,ret,0);
  for(size_t i = 0;i < ret.size();i++)
  {
    cout<<"[";
    for(size_t j = 0;j < ret[i].size();j++)
    {
      cout<<ret[i][j]<<",";
    }
    cout<<"]"<<endl;
  }
}

//方法三：循环枚举
vector<vector<int>> subsets2(vector<int>& arr)
{
  vector<vector<int>> ret;

  //放一个空集
  ret.push_back({});

  //遍历arr中的每个元素
  for(size_t i = 0;i < arr.size();i++)
  {
    //此处一定要保存ret的大小
    size_t size = ret.size();

    //遍历ret中的每个元素
    for(size_t j = 0;j < size;j++)
    {
      vector<int> track = ret[j];
      track.push_back(arr[i]);
      ret.push_back(track);
    }
  }
  return ret;
}

int main()
{
  vector<int> arr = {1,2,3};
  vector<vector<int>> ret = subsets2(arr);
  for(auto e : ret)
  {
    cout<<"[";
    for(auto m : e)
    {
      cout<<m<<" ";
    }
    cout<<"]"<<endl;;
  }
  return 0;
}
