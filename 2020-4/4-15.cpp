#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> dp(n);//保存从前往后和从后往前遍历的结果
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  stack<int> l,r;//单调栈

  //从后往前遍历，找到每个位置后面能看到的房子个数
  for(int i = n-1;i > 0;i--)
  {
    //如果栈顶元素比当前元素小，说明我这个高个子挡住后面矮个子的房子了
    //那么从当前位置往后面看，肯定就看不到矮个子的房子，只看到高个子的房子
    //所以可以直接pop掉矮个子的房子
    while (!r.empty() && arr[i] >= r.top())
      r.pop();
    r.push(arr[i]);
    dp[i - 1] = r.size();
  }

  //注意边界问题：从后往前没有计算到0，在1的时候就把0计算了
  cout<<dp[0] + 1<<" ";
  //从后往前遍历，找到每个位置前面能看到的房子个数
  for(int i = 0;i < n-1;i++)
  {
    //同理
    while (!l.empty() && arr[i] >= l.top())
      l.pop();
    l.push(arr[i]);
    dp[i + 1] += l.size() + 1;
    cout<<dp[i + 1]<<" ";
  }
}

}
}
}
