#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 10

//注意数组存储下标代表每一行，数组元素代表皇后在每一行的位置
int hei[MaxSize];//黑皇后
int bai[MaxSize];//白皇后
int chessboard[MaxSize][MaxSize];//1:能放  0:不能放
int count = 0;//记录共有多少种放皇后的位置

int Check(int *str, int line)//该函数判断皇后是否能够放置在str[line]这个位置
{
	int i = 1;
	for (;i < line;i++)
	{
		int temp = str[i] - str[line];
		if (temp == 0 || temp == i - line || temp == line - i)
			//temp == 0，表示皇后在同一列；temp == i - line 和 temp == line - i代表皇后在正反对角线
		{
			return 0;
		}
	}
	return 1;
}

void Whilte(int n, int line)
{
	if (line == n + 1)
	{
		count++;
	}
	else
	{
		for (int i = 1;i <= n;i++)//i空值第line行的每一列
		{
			if (chessboard[line][i] == 1&&hei[line]!=i)//判断该位置是否可以放皇后
			{
				bai[line] = i;//记录第line行皇后的位置
				if (Check(bai, line))//进行判断，满足条件就递归下一行
				{
					Whilte(n, line + 1);
				}
			}
		}
	}
}

void Black(int n, int line)//该函数放黑皇后
{
	if (line == n+1)//如果行line等于n+1;说明该次递归找到一次所有黑皇后满足条件的位置，就去放白皇后
	{
		return Whilte(n, 1);
	}
	else
	{
		for (int i = 1;i <= n;i++)//i控制第line行的每一列
		{
			if (chessboard[line][i] == 1)//判断该位置是否可以放黑皇后
			{
				hei[line] = i;//记录第line行黑皇后的位置
				if (Check(hei, line))//进行判断，满足条件就递归下一行
					//注意该递归是放在循环内部的，所以当第i列不满足条件时，就会退回i-1列继续判断，即回溯
				{
					Black(n, line + 1);
				}
			}
		}
	}
}

int main()
{
	int n;
	printf("请输入棋盘大小n:\n");
	scanf("%d", &n);
	printf("请输入棋盘元素；1：该位置可以放皇后；0：该位置不可以放皇后\n");
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			printf("%d", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(n, 1);
	printf("皇后共有%d种放法\n", count);
	return 0;
}


