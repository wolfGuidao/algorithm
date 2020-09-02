/*************************************************************************
# File Name: 8-31.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月02日 星期三 17时08分31秒
*************************************************************************/
class Solution {
public:
    //判断是否为回文
    bool IsTrue(string& str)
    {
        int wide = str.size();
        for(int j = 0;j < wide;j++)
        {        //判断是否为回文
            if(str[j] != str[wide - 1 - j])
            {
                return false;
            }
        }
        return true;
    }

    //保存结果
    vector<vector<string>> res;

    void backtrack(string s,vector<string>& path,int pre)
    {
        if(pre >= s.size())
        {     
            //判断结束条件
            res.push_back(path);
            return;
        }

        //枚举开始的位置
        for(int i = pre;i < s.size();i++)
        {
            //截取子串
            string temp = s.substr(pre, i - pre + 1); //用临时变量存取分割所得的字符串

            //如果他不是回文串直接返回
            if(IsTrue(temp) == false)
            {
                continue;
            }

            //回溯
            path.push_back(temp);
            backtrack(s,path,i + 1);
            path.pop_back();    //还原

        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s,path,0);
        return res;
    }
};

