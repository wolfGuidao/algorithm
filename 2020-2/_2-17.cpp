#include "Header.hpp"

//单调栈
//给你⼀个数组 T = [73, 74, 75, 71, 69, 72, 76, 73]， 这个数组存放的是近⼏天的天⽓⽓温（这⽓温是铁板烧？ 不是的， 这⾥⽤的华⽒度） 。 你返回⼀个数组， 计算： 对于每⼀天， 你还要⾄少等多少天才能等到⼀个更暖和的⽓温；如果等不到那⼀天， 填 0

#if 0
vector<int> dailyTemperatures(vector<int>& T) 
{
  vector<int> ret(T.size(),0);
  stack<int> s;

  //到着遍历 
  for(int i = T.size() - 1;i >= 0;i--)
  {
    //如果栈不为空并且栈顶元素（后面）比当前元素（前面）小，就说明栈顶元素被当前元素给挡住了，就不用管栈顶元素了，就可以直接pop掉
    while(!s.empty() && T[s.top()] <= T[i])
    {
      s.pop();
    }

    //当前元素后面的最大元素就是栈顶元素
    ret[i] = s.empty() ? 0 : s.top() - i;
    s.push(i);
  }
  return ret;
}

int main()
{
  vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> ret = dailyTemperatures(arr);
  for(auto e : ret)
  {
    cout<<e<<" , ";
  }
  cout<<endl;
  return 0;
}
#endif

#if  1
//环状的情况
//模拟倍的长度
vector<int> nextGreaterElements(vector<int>& nums) 
{
  vector<int> ret(nums.size(),0);
  stack<int> s;

  for(int i = 2 * nums.size() - 1;i >= 0;i--)
  {
    while(!s.empty() && s.top() <= nums[i % nums.size()])
    {
      s.pop();
    }

    ret[i % nums.size()] = (s.empty() ? -1 : s.top());
    s.push(nums[i % nums.size()]);
  }
  return ret;
}

#endif 

#if 0
vector<int> nextGreaterElements(vector<int>& nums) {
  int n = nums.size();
  vector<int> res(n); // 存放结果
  stack<int> s;

  // 假装这个数组⻓度翻倍了
  for (int i = 2 * n - 1; i >= 0; i--) 
  {
    while (!s.empty() && s.top() <= nums[i % n])
      s.pop();

    res[i % n] = s.empty() ? -1 : s.top();
    s.push(nums[i % n]);
  } 
  return res;
}
#endif 

int main()
{
  vector<int> arr = {2,1,2,4,3};
  vector<int> ret = nextGreaterElements(arr);
  for(auto e : ret)
  {
    cout<<e<<" , ";
  }
  cout<<endl;
  return 0;
}
