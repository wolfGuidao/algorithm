/*************************************************************************
# File Name: 8-18.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月16日 星期日 15时25分34秒
 *************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
class A 
{
    public:
        ~A()
        {
            cout<<"~A()"<<endl;
        }
};
#endif 

class KMP
{
    public:
        KMP(const string str)
            :_str(str)
        {
            _next.resize(str.size() + 2);
            init();
        }

        void search(const string pat) 
        {
            int n = pat.size();
            int m = _str.size();

            int j = 0; //j表示当前模版串的待匹配位置
            for(int i = 0; i < n; ++i) 
            {
                while(j && pat[i] != _str[j]) 
                    j = _next[j]; //不停的转移，直到可以匹配或者走到0
                
                if(pat[i] == _str[j]) 
                    j++; //如果相等，模版串中待匹配位置可以移一位了。

                if(j == m) 
                    printf("%d\n", i - m + 1);
            }
        }


    private:
        void init() 
        {
            int n = _str.size();
            _next[0] = _next[1] = 0;
            for(int i = 1; i < n; ++i) 
            {
                int j = _next[i];
                while(j && _str[i] != _str[j]) 
                    j = _next[j]; //一旦回到1，表明窗口大小为0了，只能回到最初的字符

                _next[i + 1] = _str[i] == _str[j] ? j + 1 :0;
            }
        }

        string _str;
        vector<int> _next;
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
        {
            return 0;
        }

        sort(citations.begin(),citations.end());
        int ret = citations.size();

        for(auto e : citations)
        {
            if(e < ret)
            {
                ret--;
            }
        }
        return ret;
    }
};

int main()
{
    string str = "aabbaabbddaabbeeff";
    string pat = "aabbee";
    KMP kmp(str);
    kmp.search(pat);
    return 0;
}
