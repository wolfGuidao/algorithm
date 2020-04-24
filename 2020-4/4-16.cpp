# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main()
{
  int n,L;
  while( cin>>n>>L  )
  {
    vector<vector<int>> nums(n,vector<int>(2));
    for ( int i = 0; i < n; ++i  )
    {
      cin>>nums[i][0]>>nums[i][1];

    }

    //排序
    sort( nums.begin(), nums.end(), [](vector<int>&a, vector<int>&b)
        {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

    int begin = 0;//保存每个区间的开始位置
    int i = 0;//遍历的下标索引
    int ret = 0;//保存结果
    int end = 0;//保存每个区间的结束位置

    //开始遍历
    while(i < nums.size())
    {  
      //如果出现本次区间的begin小于等于上一个区间的end，就说明这两个
      //区间有交集，那么我们需要更新本次区间的end，选取所有处于这种
      //状态区间中最大最远的end，让覆盖长度更长，区间使用个数更少
      while( i < nums.size() && nums[i][0] <= begin  )
      {
        end = max(end, nums[i][1]);
        ++i;
      }
      //更新结果
      ++ret;
      //走到这里说明本次区间的begin已经大于上一区间的end
      //，那么我们直接把begin放到选取中最大的end位置处作为下一次
      //判断区间的开始
      begin = end;

      //如果出现本次区间的开始begin大于上一区间的结束end
      //说明两个区间没有交集，直接返回-1，因为区间没有链接上
      if (i < nums.size() && nums[i][0] > begin )
      {
        ret = -1;
        break;
      }

      //如果当前已经满足情况就直接break，无需计算了
      if ( end >= L  ) 
        break;

    }

    if ( ret == -1 || end < L  )
      cout<<-1<<endl;
    else cout<<ret<<endl;
  }
  return 0;
}


