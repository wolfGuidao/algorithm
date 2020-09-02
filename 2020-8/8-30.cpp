/*************************************************************************
# File Name: 8-30.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月02日 星期三 16时50分10秒
*************************************************************************/
class Solution {
public:
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

    vector<vector<string>> res;
    void backtrack(string s,vector<string>& path,int pre){
        if(pre >= s.size())
        {     
            //判断结束条件
            res.push_back(path);
            return;
        }

        for(int i = pre;i < s.size();i++)
        {
            string temp = s.substr(pre, i - pre + 1); //用临时变量存取分割所得的字符串
            if(IsTrue(temp) == false)
            {
                continue;
            }
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

