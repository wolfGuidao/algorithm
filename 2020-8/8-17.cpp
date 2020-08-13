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
