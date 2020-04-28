/*
 *假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其��a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
 * */


#include <iostream>
#include <string>
using namespace std;

//25 * 25 * 25 + 25 * 25 + 25 + 1
//25 * 25 + 25 + 1
//25 + 1
//1
const int arr[] = {16276, 651, 26, 1};

int main()
{
  string s;
  cin>>s;
  int ans = 0;
  for(int i = 0; i < s.length(); i++)
  {
    int if_1 = 1;
    if(i == 0) 
      if_1 = 0;

    ans += (s[i]-'a') * arr[i] + if_1;
  }
  printf("%d\n", ans);
  return 0;
}

}
}
