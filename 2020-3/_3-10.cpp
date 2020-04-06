#include "Header.hpp"
using namespace std;

//找子集
vector<vector<int>> FindSubStr(vector<int> num)
{
  //为空直接返回一个空串
  if(num.empty())
  {
    return {{}};
  }

  //每次取走最后一个元素，求前面元素的子集，如果求得前面的子集，先把结果集合中
  //的每个元素拷贝一份，再把提前保留的把最后一个元素添加到每个元素的末尾即可
  //
  //保留记录最后一个元素
  int cur = num.back();
  num.pop_back();

  //递归求当前元素前面的子集
  vector<vector<int>> temp = FindSubStr(num);

  //注意这里一定要提前保存，否则会陷入死循环
  size_t size = temp.size();

  //这个循环完成了拷贝和追加新元素
  for(size_t i = 0;i < size;i++)
  {
    //拷贝一份结果集合当中的元素，因为{1,2}和{1,2,3}同为子集，所以需要另行拷贝
    temp.push_back(temp[i]);

    //把拷贝的元素后追加一个新元素
    temp.back().push_back(cur);
  }
  return temp;
}

//方法二
vector<vector<int>> res;
vector<int> track;

//思想就是先选择第一个字符固定，再枚举后面每个字符的情况
//最后撤销回来选择另一个字符为第一个继续固定
void SubStrSet(vector<int> arr,int start,vector<int> track)
{
  //因为track只要是子集即可，没有其他要求
  res.push_back(track);

  //选择列表
  for(size_t i = start;i < arr.size();i++)
  {
    //做选择
    track.push_back(arr[i]);
    SubStrSet(arr,i + 1,track);
    //撤销选择
    track.pop_back();
  }
}

int main()
{
  vector<int> arr = {1,2,3};
  //vector<vector<int>> ret = FindSubStr(arr);
  SubStrSet(arr,0,track);
  for(auto e : res)
  {
    cout<<"[";
    for(auto m : e)
    {
      cout<< m <<",";
    }
    cout<<"]"<<endl;
  }
  return 0;
}
