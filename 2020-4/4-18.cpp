/*
 *牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
 牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
 他们的得分等于他们抽到的纸牌数字总和。
 现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


 输入描述:
 输入包括两行。
 第一行包括一个正整数n(1 <= n <= 105),表示纸牌的数量。
 第二行包括n个正整数ai(1 <= ai <= 109),表示每张纸牌上的数字。

 输出描述:
 输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。

 输入例子1:
 3
 2 7 4

 输出例子1:
 5
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0;i < n;i++)
  {
    cin>>arr[i];

  }

  sort(arr.begin(),arr.end());
  int N = arr.size() - 1;
  int sum_N = 0;
  while(N >= 0)
  {
    sum_N += arr[N];
    N -= 2;

  }
  int Y = arr.size() - 2;
  int sum_Y = 0;
  while(Y >= 0)
  {
    sum_Y += arr[Y];
    Y -= 2;

  }
  cout<<sum_N - sum_Y<<endl;
  return 0;

}
