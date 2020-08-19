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

#if 0
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

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            if(citations.empty())
            {
                return 0;
            }

            int left = 0;
            int right = citations.size();
            while(left < right)
            {
                int mid = (left + right + 1) >> 1;
                if(citations[citations.size() - mid] >= mid)
                {
                    left = mid;
                }
                else 
                {
                    right = mid - 1;
                }
            }

            return right;
        }
};
#endif


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == nullptr)
        {
            return {};
        }

        if(head->next == nullptr)
        {
            return {0};
        }

        vector<int> arr;
        ListNode* cur = head;
        while(cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        stack<int> arr_stack;
        vector<int> ret(arr.size());

        for (int i = 0; i < arr.size(); ++i)
        {
            while (!arr_stack.empty() && arr.at(i) > arr.at(arr_stack.top()))
            {
                int index = arr_stack.top();
                arr_stack.pop();

                ret.at(index) = arr.at(i);
            }

            arr_stack.push(i);
        }
        return ret;
    }
};

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        if(A.empty())
        {
            return 0;
        }

        /*
        vector<int> left(A.size());
        vector<int> right(A.size());

        left[0] = A[0];
        for(int i = 1;i < A.size();i++)
        {
            int max_val = max(A[i],left[i - 1]);
            left[i] = max_val;
        }

        right[A.size() - 1] = A.back();
        for(int i = A.size() - 2;i >= 0;i--)
        {
            int min_val = min(A[i],right[i + 1]);
            right[i] = min_val;
        }

        for(int i = 0;i < A.size() - 1;i++)
        {
            if(left[i] <= right[i + 1])
            {
                return i + 1;
            }
        }   

        */

        //标记结果下标
        int ret = 0;

        //代表[0,ret]的最大值
        int max_val = A[0];

        //代表[0,i]的最大值
        int cur_max_val = A[0];

        for(int i = 0;i < A.size();i++)
        {
            //更新cur_max_val
            cur_max_val = max(cur_max_val,A[i]);

            //如果大于等于[0,ret]之间最大的元素就直接跳过
            if(A[i] >= max_val)
            {
                continue;
            }

            //标记第一个出现小于的位置，我们后续要满足比[0,ret]区间最大的元素都大，否则一值更新ret
            //直到等于A的长度
            ret = i;

            //更新[0,ret]范围内的最大值
            max_val = cur_max_val;
        }

        return ret + 1;
    }
};

#include <string.h>

void GetNext(char* p,int next[])
{
    if(p == nullptr)
    {
        return ;
    }

    int k = -1;
    int j = 0;
    next[0] = -1;
    int pLen = strlen(p);
    while(j < pLen - 1)
    {
        if(k == -1 || p[j] == p[k])
        {
            k++;
            j++;
            next[j] = k;
        }
        else 
        {
            k = next[k];
        }
    }
}

int KmpSearch(char* s,char* p)
{
    if(s == nullptr || p == nullptr)
    {
        return -1;
    }

    int next[1024];
    GetNext(p,next);
    int i = 0;
    int j = 0;
    int pLen = strlen(p);
    int sLen = strlen(s);

    while(i < sLen && j < pLen)
    {
        if(j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else 
        {
            j = next[j];
        }

        if(j == pLen)
        {
            cout<<i - j<<endl;
            j = next[j];
        }
    }


    return i - j;
}

int main()
{
    char str[] = "aabbaabbddaabbeeff";
    char pat[] = "aabb";
    KmpSearch(str,pat);
    return 0;
}
