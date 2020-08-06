/*************************************************************************
  > File Name: 7-30.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月11日 星期六 18时00分05秒
 ************************************************************************/

#include "Header.hpp"

#include<iostream>
#define MAX_NUM 100
using namespace std;
 
void FindSum(int n)
{
    if(n <= 0)
        return;
        
    int sum = 0;
    int arr[n + 1][6 * n + 1];
    memset(arr,0,sizeof(arr));
    
    for(int i = 1; i <= 6; i++)//初始状态：base case
        arr[1][i] = 1;
        
    for(int i = 2; i <= n; i++)//状态转移方程
    {
        for(int j = i;j <= 6 * i; j++)//注意j的范围受i影响
        {
            arr[i][j] += (arr[i - 1][j - 1] + arr[i - 1][j - 2] 
            + arr[i - 1][j - 3] + arr[i - 1][j - 4] + 
            + arr[i - 1][j - 5] + arr[i - 1][j - 6]);
        }
    }
    
    //输出结果
    //for(int i = n; i <= 6 * n; i++)
    //{
    //    sum += arr[n][i];
    //}

    //for(int i = n; i <= 6 * n; i++)
    //{
    //    cout<<i<<"："<<arr[n][i]<<" "<<(arr[n][i] * 1.0 / sum)<<endl;
    //}
}


#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 3;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
    	scanf("%d", &a[i]);
    	
    //先排序使所有数字满足第一个条件
    sort(a, a + n);
    
    //特殊情况，直接返回即可
    if(n == 1) 
    	printf("%d\n", 2); 
    else if(n == 2) 
    {
        if(a[1] - a[0] > 20) 
        	printf("%d\n", 4);
        	//1，1000，只能添加4个构成1，x1，x2和y1，y2，1000
        else 
        	//说明小于20大于10；即1，15只需要添加一个就可以满足情况
        	printf("%d\n", 1);
    }
    else
    {
    	//遍历的下标指针
        int l = 0;
        //记录结果
  		int add = 0;
  		
  		//因为在当前位置往后判断2个位置了，所以之一范围
        while(l < n - 2)
        {
        	//分析中的第一种情况
            if(a[l + 1] - a[l] <= 10 && a[l + 2] - a[l + 1] <= 10) 
            	l += 3;
            //分析中的第二种情况
            else if(a[l + 1] - a[l] > 20) 
            {
            	add += 2; 
            	l += 1;
            }
            //分析中的第三种情况
            else if(a[l + 1] - a[l] <= 20 && a[l + 1] - a[l] > 10) 
            {
            	add++;
            	l += 2;
            }
            //分析中的第四种情况
            else if(a[l + 1] - a[l] <= 10 && a[l + 2] - a[l + 1] > 10) 
            {
            	add++;
            	l += 2;
            }
            
            //如1，2，3，4这种情况，在判断1时发现满足情况，指针直接+3，发现3 < 2
            //不成立，但是不能直接推出，因为还有4没构成3个，所以直接+2即可
            if(l == n - 1) 
            	add += 2;

			//这种情况同理;1,2,3,4,9999这种情况，在下标指针指向4时，发现3 < 3
			//不成立，也不能直接推出，只需要+4构成两队即可
            if(l == n - 2) 
            {
                if(a[l + 1] - a[l] > 20) 
                	add += 4;
                else 
                	add += 1;
            }
        }
        printf("%d\n", add);
    }
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ret;

    void GetSum(TreeNode* root,int sum,vector<int>& track)
    {
        if(root == nullptr)
        {
            return ;
        }

        track.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && sum == root->val)
        {
            ret.push_back(track);
            //return ;
        }

        
            
            GetSum(root->left,sum - root->val,track);
            GetSum(root->right,sum - root->val,track);
            track.pop_back();
        
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
        {
            return {};
        }

        vector<int> track;
        GetSum(root,sum,track);

        return ret;
    }
};
