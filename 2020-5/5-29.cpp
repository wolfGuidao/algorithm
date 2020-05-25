#include "Header.hpp"

#if 0
vector<vector<int>> subsets(vector<int>& nums) {
	// base case，返回一个空集
	if (nums.empty()) 
		return {{}};

	// 把最后一个元素拿出来
	int n = nums.back();
	nums.pop_back();

	// 先递归算出前面元素的所有子集
	vector<vector<int>> res = subsets(nums);

	int size = res.size();
	for (int i = 0; i < size; i++) 
	{
		// 然后在之前的结果之上追加
		res.push_back(res[i]);

		//在每个结果后面push一个前面保存的元素n
		res.back().push_back(n);
		//eg:{1,2} : {},{1},{2},{1,2} 
		//n = 2  res = subsets()
		//     n = 1    res = sunsets()
		//              res = { {} }
		//	   i = 0; i < 1;i ++
		//     res = { {}, {} }
		//	   res = { {},{1} }
		//i = 0;i < 2;i ++
		//res = { {},{1},{} }
		//res = { {},{1},{2} }
		//res = { {},{1},{2},{1} }
		//res = { {},{1},{2},{1,2} }
	}

	return res;
}

#endif 

vector<vector<int>> ret;

void backtrack(vector<int>& nums, int start, vector<int>& track)
{
	ret.push_back(track);
	for(size_t i = start;i < nums.size();i++)
	{
		track.push_back(nums[i]);
		backtrack(nums,i + 1, track);
		track.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	// 记录走过的路径
	vector<int> track;
	backtrack(nums, 0, track);
	return ret;
}

vector<vector<int>>res;

vector<vector<int>> combine(int n, int k) {
	if (k <= 0 || n <= 0) 
		return res;

	vector<int> track;
	backtrack(n, k, 1, track);
	return res;
}

void backtrack(int n, int k, int start, vector<int>& track) {
	// 到达树的底部
	if (k == track.size()) 
	{
		res.push_back(track);
		return;
	}

	// 注意 i 从 start 开始递增
	for (int i = start; i <= n; i++) {
		// 做选择
		track.push_back(i);
		backtrack(n, k, i + 1, track);
		// 撤销选择
		track.pop_back();
	}
}

class Solution {
public:
    vector<vector<int>> ret;//保存最后的结果
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
        {
            return ret;
        }

        vector<int> track;//保存单次结果
        backtrack(nums,track);//递归
        return ret;
    }

    void backtrack(vector<int>& nums,vector<int>& track)
    {
        if(track.size() == nums.size())//当track中的元素和nums中的元素个数相等
        //时，代表是一种全排列，可以放到ret的结果中
        {
            ret.push_back(track);
            return;
        }

        //循环回朔
        for(int i = 0;i < nums.size();i++)
        {
            //如果nums[i]这个元素已经存在track中，代表上次的选择错误，
            //continue回去，判断下一个元素
            //反之，就把nums这个元素直接放到track中，继续回朔判断
            if(IsExist(track,nums[i]))
            {
                track.push_back(nums[i]);
            }
            else
            {
                continue;
            }

            backtrack(nums,track);

            //撤销选择
            track.pop_back();
        }
    }

    //在track中判断一个元素是否已经存在
    bool IsExist(vector<int>& track,int val)
    {
        for(auto e : track)
        {
            if(e == val)
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
	vector<int> nums{1, 2, 3};
	vector<vector<int>> temp = subsets(nums);
	for(auto e : temp)
	{
		cout<<"[";
		for(auto m : e)
		{
			cout<<" "<<m<<" ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}
