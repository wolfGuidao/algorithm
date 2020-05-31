/*************************************************************************
  > File Name: 6-13.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年05月31日 星期日 16时26分37秒
 ************************************************************************/

#include "Header.hpp"

int base = 1337;

// 计算 a 的 k 次方然后与 base 求模的结果
int mypow(int a, int k) 
{
    // 对因子求模
    a %= base;
    int res = 1;
    for (int _ = 0; _ < k; _++) 
    {
        // 这里有乘法，是潜在的溢出点
        res *= a;
        
        // 对乘法结果求模
        res %= base;
    }
    return res;
}

int superPow(int a, vector<int>& b) 
{
    if (b.empty()) 
    	return 1;
    
    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);
    
    // 每次乘法都要求模
    return (part1 * part2) % base;
}


int base = 1337;

int mypow(int a, int k) 
{
    if (k == 0) 
    	return 1;
    
    a %= base;

    if (k % 2 == 1) 
    {
        // k 是奇数
        return (a * mypow(a, k - 1)) % base;
    } 
    else 
    {
        // k 是偶数
        int sub = mypow(a, k / 2);
        return (sub * sub) % base;
    }
}



int main()
{

  return 0;
}

