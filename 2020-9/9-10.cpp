/*************************************************************************
# File Name: 9-10.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年09月10日 星期四 16时13分18秒
*************************************************************************/

#include <iostream>
using namespace std;

inline void Print()
{
    cout<<"inline"<<endl;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Reverse(ListNode* head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* last = Reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return last;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return ;
        }

        //找到链表的中间节点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //把链表的后一半给翻转，得到翻转后的新节点
        ListNode* new_head = Reverse(slow->next);

        //断开链接
        slow->next = nullptr;

        ListNode* new_head_cur = new_head;
        //4 5

        ListNode* head_cur = head;
        //1 2 3

        //把新链表插入到原链表当中
        while(new_head_cur)
        {
            //保存下一个
            ListNode* node_next = head_cur->next;
            ListNode* new_node_next = new_head_cur->next;

            //链接
            head_cur->next = new_head_cur;


            //下一个
            new_head_cur->next = node_next;
            new_head_cur = new_node_next;

            //链接
            head_cur = node_next;
        }
    }
};

int i = 1;
int main()
{
    int i = 26.8 % 2;
    cout<<i<<endl;
    Print();
    return 0;
}


class Solution {
public:
    string reverseWords(string s) {
        if(s.empty() || s == "")
        {
            return "";
        }

        int start = 0;
        while(start < s.size() && s[start] == ' ')
        {
            start++;
        }

        int end = s.size() - 1;
        while(end >= 0 && s[end] == ' ')
        {
            end--;
        }

        if(start > end)
        {
            return "";
        }
        string temp = s.substr(start,end - start + 1);
        string str = "";
        int i = 0;
        while(i < temp.size())
        {
            while(i < temp.size() && temp[i] != ' ')
            {
                str += temp[i];
                i++;
            }

            if(i == temp.size())
            {
                break;
            }

            str += ' ';
            while(temp[i] == ' ')
            {
                i++;
            }
        }

        reverse(str.begin(),str.end());

        int index = 0;
        int begin = 0;
        while(index < str.size())
        {
            while(index < str.size() && str[index] != ' ')
            {
                index++;
            }

            reverse(str.begin() + begin,str.begin() + index);
            
            index++;

            begin = index;
        }

        return str;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _inner(root);
        _index = 0;
        _size = _arr.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return _arr[_index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(_index < _size)
        {
            return true;
        }

        return false;
    }
    private:
    void _inner(TreeNode* root)
    {
        if(root)
        {
            _inner(root->left);
            _arr.push_back(root->val);
            _inner(root->right);
        }
    }

    vector<int> _arr;
    int _index;
    int _size;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class Solution {
public:
    class cmp 
    {
        public:
        bool operator()(int left,int right)
        {
            string a = to_string(left) + to_string(right);
            string b = to_string(right) + to_string(left);
            return a > b;
        }
    };

    string largestNumber(vector<int>& nums) {
        if(nums.empty())
        {
            return "";
        }

        if(nums.size() == 1)
        {
            return to_string(nums[0]);
        }

        sort(nums.begin(),nums.end(),cmp());

        string ret = "";
        for(auto e : nums)
        {
            ret += to_string(e);
        }

        if(ret[0] == '0')
        {
            return "0";
        }

        return ret;
    }
};

