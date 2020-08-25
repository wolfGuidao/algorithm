/*************************************************************************
# File Name: 8-23.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月25日 星期二 22时00分56秒
*************************************************************************/

class Solution {
public:
    string add(string& a,string& b)
    {
        int n1 = a.size() - 1;
        int n2 = b.size() - 1;
        int carry = 0;
        string ans;
        while(n1 >= 0 || n2 >= 0 || carry > 0)
        {
            int t1 = n1 >= 0 ? a[n1--] - '0' : 0;
            int t2 = n2 >= 0 ? b[n2--] - '0' : 0;
            ans += (t1 + t2 + carry) % 10 + '0';
            carry = (t1 + t2 + carry) >= 10 ? 1 : 0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool dfs(string& str,int i,int j,int k)
    {
        if((str[i] == '0' && i + 1 < j) || (str[j] == '0' && j + 1 < k))
        {
            return false;
        }

        string num1 = str.substr(i,j - i);
        string num2 = str.substr(j,k - j);
        string add_num = add(num1,num2);

        int n = add_num.size();
        if(n > str.size() - k)
        {
            return false;
        }
        
        string num3 = str.substr(k,n);
        if(num3 != add_num)
        {
            return false;
        }

        if(k + n == str.size())
        {
            return true;
        }

        return dfs(str,j,k,k + n);
    }

    bool isAdditiveNumber(string num) {
        if(num.size() < 3)
        {
            return false;
        }

        int i = 0;
        for(int j = i + 1;j < num.size();j++)
        {
            for(int k = j + 1;k < num.size();k++)
            {
                if(dfs(num,i,j,k))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

