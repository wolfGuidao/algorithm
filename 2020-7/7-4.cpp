/*************************************************************************
  > File Name: 7-4.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月24日 星期三 13时49分10秒
 ************************************************************************/

#include "Header.hpp"
#include <limits.h>

#if 0
class Solution {
    public:
        vector<vector<int>> lastresult;
        vector<vector<int>> findsubsets(vector<int>& nums, int k){
            vector<vector<int>> result;
            //主要思想是递归：如果你知道前k - 1个元素的所有子集，那么整个数组的子集就是往前k - 1个元素的所有子集的尾部在push第k个元素，当数组中没有元素时，在push一个空集
            //递归出口是当k == 0 时，往result中放一个空集，空集是任何数组的子集
            if(k==0)
            {
                lastresult.push_back({});
            }
            else
            {
                lastresult = findsubsets(nums, k-1);//进入递归
                result = lastresult;//保存当前的所有子集
                int size = lastresult.size();
                for(int i = 0; i < size; i++)
                {
                    lastresult.push_back(lastresult[i]);
                    lastresult.back().push_back(nums[k-1]); //把每个子集尾部push第k-1个元素作为新的子集，继续放到result数组中
                }
            }
            return lastresult;
        }

        vector<vector<int>> subsets(vector<int>& nums) 
        {
            return findsubsets(nums,nums.size());
        }
};



int main()
{

    vector<int> arr{1,2,3};
    vector<vector<int>> ret = Solution().subsets(arr);
    for(size_t i = 0;i < ret.size();i++)
    {
        cout<<"[";
        for(size_t j = 0;j < ret[0].size();j++)
        {
            cout<<ret[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
#endif 

class Solution {
    public:
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int dfs(vector<vector<int>> arr,int x,int y)
        {
            //两种写法:ret = 1是因为字符本身肯定在递增串当中
            int ret = 1;
            //ret = 0是因为返回时进行++
            //int ret = 0;
            //在每一个位置往4个方向枚举
            for(auto e : dir)
            {
                int new_x = x + e[0];
                int new_y = y + e[1];

                if(new_x >= 0 && new_x < arr.size() && new_y >= 0 && new_y < arr[0].size() && arr[new_x][new_y] > arr[x][y])
                {
                    ret = max(ret,dfs(arr,new_x,new_y) + 1);
                }
            }
            //在这里++是因为如果一旦有一个方向满足情况，就会递归下去，退出for循环代表没有满足的条件或者已经遍历完
            //4个方向，返回++，代表这一个数字在结果集当中
            //return ++ret;
            return ret;
        }

        int longestIncreasingPath(vector<vector<int>>& matrix) { 
            if(matrix.empty())
            {
                return 0;
            }
            
            int ret = INT_MIN;
            for(size_t i = 0;i < matrix.size();i++)
            {
                for(size_t j = 0;j < matrix[0].size();j++)
                {
                    ret = max(ret,dfs(matrix,i,j));
                }
            }
            return ret;
        }
};

int main()
{
    //vector<vector<int>> arr = {{9,9,4},{6,6,8},{2,1,1}};
    //vector<vector<int>> arr = {{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>> arr = {{0,1,2},{0,0,0},{0,0,10}};
    cout<<Solution().longestIncreasingPath(arr)<<endl;
    return 0;
}
