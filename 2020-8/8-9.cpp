/*************************************************************************
# File Name: 8-9.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月24日 星期五 12时30分25秒
*************************************************************************/
class Solution {
public:

    /*
    vector<string> arr;

    bool IsExist(vector<string> arr,string str)
    {
        for(auto e : arr)
        {
            if(e == str)
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(string str,int start)
    {
        if(start == str.size() - 1)
        {
            if(IsExist(arr,str))
            {
                arr.push_back(str);
            }
        }

        for(int i = start;i < str.size();i++)
        {
            swap(str[i],str[start]);
            backtrack(str,start + 1);
            swap(str[i],str[start]);
        }
    }

    bool IsTrue(string str)
    {
        stack<char> s;
        for(auto e : str)
        {
            if(e == '(')
            {
                s.push(e);
            }
            else 
            {   
                if(!s.empty())
                {
                    s.pop();
                }
                else 
                {
                    return false;
                }
            }
        }

        if(s.empty())
        {
            return true;
        }
        else 
        {
            return false;
        }

    }
*/
    void backtrack(vector<string>& ret,string str,int left,int right,int num)
    {
        if(str.size() == 2 * num)
        {
            ret.push_back(str);
        }

        if(left < num)
        {
            str.push_back('(');
            backtrack(ret,str,left + 1,right,num);
            str.pop_back();
        }

        if(right < left)
        {
            str.push_back(')');
            backtrack(ret,str,left,right + 1,num);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        /*
        string str;
        for(int i = 0;i < n;i++)
        {
            str += "()";
        }

        backtrack(str,0);

        vector<string> ret;
        for(auto e : arr)
        {
            if(IsTrue(e))
            {
                ret.push_back(e);
            }
        }
        return ret;
        */

        vector<string> ret;

        string str;

        backtrack(ret,str,0,0,n);

        return ret;
    }
};

