/*************************************************************************
# File Name: 8-29.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月02日 星期三 10时14分38秒
*************************************************************************/

class Solution {
public:
    bool isNumber(string s) {
        //1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
        int i = s.find_first_not_of(' ');
        if(i == string::npos)
            return false;
        
        int j = s.find_last_not_of(' ');
        s = s.substr(i,j - i + 1);
        if(s.empty())
            return false;

        //2、根据e来划分底数和指数
        int e = s.find('e');
        int E = s.find('E');
        e = e == -1 ? E : e;
        //cout<<s.substr(0,e)<<endl;
        //cout<<s.substr(e+1)<<endl;

        //3、指数为空，判断底数
        if(e == string::npos)
            return judgeP(s);
        //4、指数不为空，判断底数和指数
        else 
            return judgeP(s.substr(0,e))&&judgeS(s.substr(e + 1));
    }

    bool judgeP(string s)//判断底数是否合法
    {
        bool result = false,point = false;
        int n = s.size();
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                //符号位不在第一位，返回false
                if(i != 0)
                    return false;
            }
            else if(s[i] == '.')
            {
                if(point)
                    return false;//有多个小数点，返回false
                point = true;
            }
            else if(s[i] < '0' || s[i] > '9')
            {
                //非纯数字，返回false
                return false;
            }
            else
            {
                result = true;
            }
        }
        return result;
    }

    bool judgeS(string s)//判断指数是否合法
    {   
        bool result = false;
        //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                //符号位不在第一位，返回false
                if(i != 0)
                    return false;
            }
            else if(s[i] < '0' || s[i] > '9')
            {
                //非纯数字，返回false
                return false;
            }
            else
            {
                result = true;
            }
        }
        return result;
    }
};

