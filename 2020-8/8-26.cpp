/*************************************************************************
# File Name: 8-26.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月28日 星期五 13时31分53秒
*************************************************************************/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        /*
        int ret = 0;
        int index = 0;
        while(index < nums.size())
        {
            if(index == 0 && index + 1 < nums.size() && nums[index] > nums[index + 1])
            {
                ret = index;
                break;
            }

            if(index - 1 >= 0 && index + 1 < nums.size())
            {
                if(nums[index - 1] < nums[index] && nums[index] > nums[index + 1])
                {
                    ret = index;
                    break;
                }
            }

            if(index == nums.size() - 1 && index - 1 >= 0 && nums[index] > nums[index - 1])
            {
                ret = index;
                break;
            }

            index++;
        }
        return ret;
        */

        int l = 0, r = nums.size() - 1;
        while (l < r) 
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;

    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        int i = 0;
        int j = 0;
        while(i < n1 || j < n2)
        {
            int index1 = i;
            int index2 = j;
            while(index1 < n1 && version1[index1] != '.')
            {
                index1++;
            }

            while(index2 < n2 && version2[index2] != '.')
            {
                index2++;
            }

            int num1 = (index1 == i ? 0 : stoi(version1.substr(i,index1 - i)));
            int num2 = (index2 == j ? 0 : stoi(version2.substr(j,index2 - j)));
            if(num1 > num2)
            {
                return 1;
            }
            else if(num1 < num2)
            {
                return -1;
            }
            i = index1 + 1;
            j = index2 + 1;
        }

        return 0;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //思想是：删除
        //删除左右边界中距离x远的n - k个元素，保留k个
        vector<int> ret;
        int count = arr.size() - k;
        int left = 0;
        int right = arr.size() - 1;
        while(count--)
        {
            if(abs(arr[left] - x) > abs(arr[right] - x))
            {
                left++;
            }
            else if(abs(arr[left] - x) <= abs(arr[right] - x))
            {
                right--;
            }
        }

        for(int i = left;i <= right;i++)
        {
            ret.push_back(arr[i]);
        }
        return ret;
    }
};

class Solution {
public:
    /* 计算 p[j..] 是否匹配 s[i..] */
	bool dp(string& s, int i, string& p, int j) 
	{
    	int m = s.size(), n = p.size();

		if (i == s.size()) 
		{
    		// 如果能匹配空串，一定是字符和 * 成对儿出现
    		if ((n - j) % 2 == 1) 
    		{
        		return false;
    		}
    		// 检查是否为 x*y*z* 这种形式
    		for (; j + 1 < p.size(); j += 2) 
    		{
        		if (p[j + 1] != '*') 
        		{
            		return false;
        		}
    		}
    		return true;
		}

    	if (s[i] == p[j] || p[j] == '.') 
    	{
        	// 匹配
        	if (j < p.size() - 1 && p[j + 1] == '*') 
        	{
            	// 通配符匹配 0 次或多次
            	return dp(s, i, p, j + 2)
                	|| dp(s, i + 1, p, j);
        	} 
        	else 
        	{
            	// 常规匹配 1 次
            	return dp(s, i + 1, p, j + 1);
        	}
    	} 
    	else 
    	{
        	// 不匹配
        	if (j < p.size() - 1 && p[j + 1] == '*') 
        	{
            	// 通配符匹配 0 次
            	return dp(s, i, p, j + 2);
        	} 
        	else 
        	{
            	// 无法继续匹配
            	return false;
        	}
    	}
	}
	
    // 动态规划
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);   
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();

        if(p.empty()) 
            return s.empty();

        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));

		//初始化为true，因为空和空肯定是匹配的
        dp[0][0] = true;

		//这里的base case是初始化*匹配0次的情况
        for(int i = 1; i <= np; i++)
        {
            if(i - 2 >= 0 && p[i - 1] == '*' && p[i - 2])
            {
                dp[0][i] = dp[0][i - 2];
            }
        }
        
        //开始状态转移
        for(int i = 1; i <= ns; i++)
        {
            for(int j = 1; j <= np; j++)
            {
            	//p的前一个字符和s的前一个字符相等会p的前一个字符是'.'直接转移
                if(p[j - 1] == s[i - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];

				//如果p的前一个为'*'就需要考虑匹配0次和多次了
                if(p[j - 1] == '*')
                {
                    bool zero, one;
                    if(j - 2 >= 0)
                    {
                    	//匹配0次
                        zero = dp[i][j - 2];
                        //匹配多次
                        one = (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                        dp[i][j] = zero || one;
                    }
                }
            }
        }
        return dp[ns][np];
    }
};

