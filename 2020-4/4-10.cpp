#include "Header.hpp"
/*
 *为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。

 输入描述:
 每个输入包含一个测试用例。
 每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
 接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
 保证不存在两项工作的报酬相同。

 输出描述:
 对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

 示例1
 输入
 3 3 
 1 100 
 10 1000 
 1000000000 1001 
 9 10 1000000000

 输出
 100 
 1000 
 1001
 * */
#if 1
typedef pair<int,int>pii;

const int N=100010;

pii dat[N],a[N];//代表工作难度、薪资信息和伙伴能力信息
int ans[N];//保存结果

void solve()
{
  int n,m;
  scanf("%d%d",&n,&m);

  for(int i=1;i<=n;i++) 
    scanf("%d%d",&dat[i].first,&dat[i].second);

  sort(dat + 1,dat + n + 1);

  for(int i = 1;i <= m;i++) 
    scanf("%d",&a[i].first),a[i].second=i;

  sort(a + 1,a + m + 1);

  int cur=0;//代表所能获得的薪资
  int i = 1;//代表工作信息的下标
  for(int j = 1;j <= m;j++)
  {
    //如果出现工作难度小于伙伴的能力，就更新所能获得的薪资，并把工作信息的小标++，找更高下薪资
    while(i <= n && dat[i].first <= a[j].first)
    {
      cur = max(cur,dat[i].second);
      i++;
    }

    //代表找到j这个人的薪资，保存
    ans[a[j].second] = cur;

  }
  for(int i = 1;i <= m;i++) 
    printf("%d\n",ans[i]);

}

int main()
{
  solve();
  return 0;
}
#endif 