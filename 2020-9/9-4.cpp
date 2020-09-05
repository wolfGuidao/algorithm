/*************************************************************************
# File Name: 9-4.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月05日 星期六 20时55分43秒
*************************************************************************/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;

        // 维护一个计数器记录字符串中字符的数量
        // 因为输入为 ASCII 字符，大小 256 够用了
        vector<int> count(256,0);
        for (int i = 0; i < s.size(); i++) 
        {
            count[s[i]]++;
        }

        vector<bool> inStack(256,false);
        for (char& c : s) 
        {
            // 每遍历过一个字符，都将对应的计数减一
            count[c]--;

            if (inStack[c]) 
        	    continue;

            while (!stk.empty() && stk.top() > c) 
            {
                // 若之后不存在栈顶元素了，则停止 pop
                if (count[stk.top()] == 0) 
                {
                    break;
                }
                // 若之后还有，则可以 pop
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }

        string ret;
        while (!stk.empty()) 
        {
            ret += stk.top();
            stk.pop();
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};

