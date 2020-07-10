/*************************************************************************
  > File Name: 7-28.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月10日 星期五 11时56分04秒
 ************************************************************************/

#include "Header.hpp"

class A 
{
    public:
        A()
        {}

        A(const int& a)
            :_a(a)
        {}

    private:
        int _a;
};


#include<iostream>
using namespace std;
 
double luck(double n)
{
	if(n == 1 || n == 2)
	{
		return n - 1;
	}
	
	return ((n - 1)*(luck(n - 1) + luck(n - 2)));
}
	
int main()
{
	double n;
	while (cin >> n)
	{
		//错排的方案数
		double lu = luck(n);

		//总的方案数
		double all = 1;
		for (double i = 1;i <= n;++i)
		{
			all *= i;
		}
		
		//概率
		lu = lu / all*100;
		
		printf("%.2f%%\n", lu);
	}
	return 0;
}
