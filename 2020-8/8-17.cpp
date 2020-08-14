/*************************************************************************
# File Name: 8-17.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月11日 星期二 22时34分51秒
 *************************************************************************/
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        vector<vector<int>> s(increase.size() + 1,vector<int>(3,0));
        for(int i = 0;i < increase.size();i++)
        {
            for(int j = 0;j < 3;j++)
            {
                s[i + 1][j] = s[i][j] + increase[i][j];
            }
        }
        vector<int> ans;
        for(auto v:requirements)
        {
            int l = 0, r = increase.size();
            while(l < r)
            {
                int m = (l + r) / 2;
                if(s[m][0] >= v[0] && s[m][1] >= v[1] && s[m][2] >= v[2])
                    r = m;
                else
                    l = m + 1;
            }
            if(s[l][0] >= v[0] && s[l][1] >= v[1] && s[l][2] >= v[2])
                ans.push_back(l);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> ret;

    bool IsTrue(vector<int>& arr1,vector<int>& arr2)
    {
        if(arr1.size() != arr2.size())
        {
            return false;
        }

        int index = 0;
        while(index < arr1.size())
        {
            if(arr1[index] != arr2[index])
            {
                return false;
            }
            index++;
        }

        return true;
    }

    bool IsValied(vector<int>& arr)
    {
        for(auto e : ret)
        {
            if(IsTrue(e,arr))
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<int>& nums,int index)
    {
        if(index == nums.size())
        {
            //if(IsValied(nums))
            if(find(ret.begin(),ret.end(),nums) == ret.end())
            {
                ret.push_back(nums);
            }
                
            return ;
        }

        for(int i = index;i < nums.size();i++)
        {
            if (i > index && nums[i] == nums[i - 1])
				continue;
            swap(nums[i],nums[index]);
            backtrack(nums,index + 1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }

        backtrack(nums,0);

        return ret;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();

        //(n + 1) / 2为总的循环次数，也就是层数，每一圈旋转完毕后矩阵缩小一圈，
        // + 1的目的是向上取整
        for (int i = 0; i < (n + 1) / 2; i ++) 
        {
            //j可以理解为add
            for (int j = 0; j < n / 2; j++) 
            {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
        {
            return {};
        }   

        /*
        unordered_map<string,vector<string>> my_map;
        for(auto& e : strs)
        {
            string str(e);
            sort(str.begin(),str.end());

            my_map[str].push_back(e);
        }

        vector<vector<string>> ret;
        for(auto e : my_map)
        {
            ret.push_back(e.second);
        }

        return ret;
        */

         vector<vector<string>> res;
        unordered_map <double,vector<string>> m;
        double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            double t = 1;
            for(char c : s)
            t *= a[c - 'a'];

            m[t].push_back(s);
        }
        for(auto& n : m)
            res.push_back(n.second);
        return res;
    }
};

class Solution {
public:
    double GetNum(double x,int n)
    {
        if(n == 0)
        {
            return 1;
        }

        if(n == 1)
        {
            return x;
        }

        double temp = GetNum(x,n / 2);
        if(n % 2 != 0)
        {
            return x * temp * temp;
        }
        else 
        {
            return temp * temp;
        }
    }

    double myPow(double x, int n) {
        if(n == 0)
        {
            return 1.0;
        }
        if(x == 0)
        {
            return 0.0;
        }

        int flag = 1;
        int count = abs(n);
        if(n < 0)
        {
            flag = 0;
        }

        double ret = GetNum(x,count);
        if(flag)
            return ret;
        
        return 1.0 / ret;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return {};
        }

        vector<int> ret;

        //左边界
        int left = 0;

        //右边界
        int right = matrix[0].size() - 1;

        //上边界
        int top = 0;

        //下边界
        int down = matrix.size() - 1;

        while(left <= right && top <= down)
        {
            //打印左右边界之间的值，即从左往右
            for(int i = left;i <= right;i++)
            {
                ret.push_back(matrix[top][i]);
            }           

            //打印上下边界之间的值，即从上往下， + 1的原因是因为第一个元素在上一步已经打印
            for(int j = top + 1; j <= down;j++)
            {
                ret.push_back(matrix[j][right]);
            }

            //打印右左边界之间的值，即从右往左打印， - 1的原因同理
            //top != down的目的值防止只有一行的情况，当不只一行的时候才进行从右往左打印
            for(int m = right - 1;m >= left && top != down;m--)
            {
                ret.push_back(matrix[down][m]);
            }

            //打印下上边界之间的值，注意这个边界，n > top
            //left != right的原因同理，防止只有一列的情况，当不只一列的时候才进行从下往上打印
            for(int n = down - 1;n > top && left != right;n--)
            {
                ret.push_back(matrix[n][left]);
            }  

            left++;
            right--;
            top++;
            down--;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n < 1)
        {
            return {};
        }

        vector<vector<int>> ret(n,vector<int>(n));

        //左边界
        int left = 0;

        //右边界
        int right = n - 1;

        //上边界
        int top = 0;

        //下边界
        int down = n - 1;

        int num = 1;

        while(left <= right && top <= down)
        {
            //打印左右边界之间的值，即从左往右
            for(int i = left;i <= right;i++)
            {
                ret[top][i] = num++;
            }           

            //打印上下边界之间的值，即从上往下， + 1的原因是因为第一个元素在上一步已经打印
            for(int j = top + 1; j <= down;j++)
            {
                ret[j][right] = num++;
            }

            //打印右左边界之间的值，即从右往左打印， - 1的原因同理
            //top != down的目的值防止只有一行的情况，当不只一行的时候才进行从右往左打印
            for(int m = right - 1;m >= left && top != down;m--)
            {
                ret[down][m] = num++;
            }

            //打印下上边界之间的值，注意这个边界，n > top
            //left != right的原因同理，防止只有一列的情况，当不只一列的时候才进行从下往上打印
            for(int n = down - 1;n > top && left != right;n--)
            {
                ret[n][left] = num++;
            }  

            left++;
            right--;
            top++;
            down--;
        }

        return ret;
    }
};


int main()
{
    int sock = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET; 
    sock_addr.sin_addr.s_addr = inet_addr("192.168.221.132");
    sock_addr.sin_port = htons(9090);

    int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));
    if(ret < 0)
    {
        cout<<"bind error"<<endl;
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {

        //int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));
        //if(ret < 0)
        //{
        //    cout<<"bind error"<<endl;
        //    return -1;
        //}
        int ret = listen(sock,5);
        if(ret < 0)
        {
            cout<<"listen error"<<endl;
            return -1;
        }
    }
    else 
    {
        //int ret = bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr));    
        //if(ret < 0)    
        //{               
        //    cout<<"bind error"<<endl;    
        //    return -1;     
        //}    
        int ret = listen(sock,5);
        if(ret < 0)
        {
            cout<<"listen error"<<endl;
            return -1;
        }
    }
    return 0;
}
