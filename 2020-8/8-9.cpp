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

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return ret;
        }

        backtack(digits,0);

        return ret;
    }
    private:
    unordered_map<char,string> num_map = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };

    string str;
    vector<string> ret;

    void backtack(string digits,int index)
    {
        if(index == digits.size())
        {
            ret.push_back(str);
        }

        for(int i = 0;i < num_map[digits[index]].size();i++)
        {
            str.push_back(num_map[digits[index]][i]);
            backtack(digits,index + 1);
            str.pop_back();
        }
    }
};

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
    ListNode* Merge(ListNode* head1,ListNode* head2)
    {
        if(nullptr == head1)
        {
            return head2;
        }

        if(nullptr == head2)
        {
            return head1;
        }

        ListNode* new_head = nullptr;

        if(head1->val <= head2->val)
        {
            new_head = head1;
            new_head->next = Merge(head1->next,head2);
        }
        else 
        {
            new_head = head2;
            new_head->next = Merge(head1,head2->next);
        }

        return new_head;
    }

    ListNode* MergeChild(vector<ListNode*>& lists,int left,int right)
    {
        if(left == right)
        {
            return lists[right];
        }

        if(left > right)
        {
            return nullptr;
        }

        int mid = (left + right) >> 1;

        return Merge(MergeChild(lists,left,mid),MergeChild(lists,mid + 1,right));
    }

    struct Pri_Node
    {
        Pri_Node(int val,ListNode* ptr)
        :_val(val)
        ,_ptr(ptr)
        {

        }

        bool operator<(const Pri_Node node) const
        {
            return _val > node._val;
            //return _val < node._val;
            //return node1._val > node2._val;
        }

        int _val;
        ListNode* _ptr;
    };

    class cmp
    {
        bool operator()(const Pri_Node node1,Pri_Node node2)
        {
            return node1._val > node2._val;
        }
    };
    

    typedef Pri_Node Node;
    //priority_queue<Node,vector<Node>,cmp> que;
    priority_queue<Node> que;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }

        if(lists.size() == 1)
        {
            return lists[0];
        }

        /*
        ListNode* new_head = Merge(lists[0],lists[1]);

        for(int i = 2;i < lists.size();i++)
        {
            new_head = Merge(new_head,lists[i]);
        }

        return new_head;
        */

        //return MergeChild(lists,0,lists.size() - 1);

        for(auto e : lists)
        {
            if(e)
            {
                Node temp(e->val,e);
                que.push(temp);
            }
        }

        ListNode* new_head = new ListNode(0);
        ListNode* tail = new_head;
        while(!que.empty())
        {
            Node node = que.top();
            que.pop();

            tail->next = node._ptr;
            tail = tail->next;

            if(node._ptr->next)
                que.push({node._ptr->next->val,node._ptr->next});          
        }

        return new_head->next;
    }
};

