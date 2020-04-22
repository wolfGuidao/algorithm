/*
 *小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

 并且小Q对于能否被3整除这个性质很感兴趣。

 小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除�

 输入描述:
 输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。

 输出描述:
 输出一个整数, 表示区间内能被3整除的数字个数。

 示例1
 输入
 2 5
 输出
 3
 说明
 12, 123, 1234, 12345...
 其中12, 123, 12345能被3整除。
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
  int left;
  int right;
  while((scanf("%d,%d",&left,&right) != EOF))
  {

    /*
     *     if(left < 1 || right < 1)
     *         {
     *                 cout<<0;
     *                     }
     *                         
     *                             int count = 0;
     *                                 long long sum = 0;
     *                                     for(int i = 1;i < left;i++)
     *                                         {
     *                                                 sum = (sum * 10 + i);
     *                                                     }
     *                                                         for(int i = left;i <= right;i++)
     *                                                             {
     *                                                                     sum = (sum * 10 + i);
     *                                                                             if(sum % 3 == 0)
     *                                                                                     {
     *                                                                                                 count++;
     *                                                                                                         }
     *                                                                                                             }
     *                                                                                                                 
     *                                                                                                                     cout<<count<<endl;
     *                                                                                                                             */
    int count = 0;
    for(int i = left;i <= right;i++)
    {
      if(i % 3 == 0 || i % 3 == 2)
      {
        count++;

      }

    }
    cout<<count;
  }
  return 0;
}
