/*************************************************************************
  > File Name: 8-1.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月13日 星期一 19时46分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int i = 0;
    int j = 0;
	int arr[9] ;
	for (; i <= 9; i++) {
		arr[i] = 0;
		printf("hello world\n");
	}
	return 0;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return ;
        }

        //i用来标记从后往前第一个nums[x] >= nums[x + 1]的x  
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) 
        {
            i--;
        }

        //如果i小于0，就代表从后往前没找到nums[x] >= nums[x + 1]，说明整个序列
        //就是逆序的，即该序列就是最大的字典序，按题目要求，直接返回最小的字典序列

        //如果i >= 0就代表找到一个逆序对，并用i 标记x位置，那么再次从后往前遍历
        //找到第一个大于i位置的元素，因为i + 1位置（包括i + 1位置）后的所有元素都是逆序的
        //所以一定是存在这个元素的
        if (i >= 0) 
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) 
            {
                j--;
            }

            //交换
            swap(nums[i], nums[j]);
        }

        //把i + 1位置后经过交换的序列排序，相当于最小的字典序
        sort(nums.begin() + i + 1,nums.end());
    }
};

    
