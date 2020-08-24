/*************************************************************************
# File Name: 8-21.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月24日 星期一 15时00分38秒
*************************************************************************/

class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) 
    {
        //1->2->3->4->5 k = 2时
        //prev 就是3，5
        ListNode* prev = tail->next;
        ListNode* cur = head;
        while (prev != tail) 
        {
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }

        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;

        while (head) 
        {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) 
            {
                tail = tail->next;
                if (!tail) 
                {
                    return new_head->next;
                }
            }

            //ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            
            // 把子链表重新接回原链表
            pre->next = head;
            //tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return new_head->next;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int ret = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < nums.size())
        {
            sum += nums[right];
            while(sum >= s)
            {
                ret = min(ret,right - left + 1);
                sum -= nums[left];
                left++;
            }

            if(sum < s) 
            {
                right++;
            }
        }

        if(ret == INT_MAX)
            return 0;
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> ret;

    int GetSumVec(vector<int>& track)
    {
        int sum = 0;
        for(auto& e : track)
        {
            sum += e;
        }

        return sum;
    }

    void backtrack(vector<int>& arr,vector<int>& track,int index,int k,int n)
    {
        if(track.size() == k)
        {
            if(GetSumVec(track) == n)
                ret.push_back(track);
            return ;
        }

        for(int i = index;i < arr.size();i++)
        {
            track.push_back(arr[i]);
            backtrack(arr,track,i + 1,k,n);
            track.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k < 1 || n < 1)
        {
            return {};
        }

        vector<int> arr{1,2,3,4,5,6,7,8,9};
        vector<int> track;
        backtrack(arr,track,0,k,n);
        return ret;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr)
        {
            return head;
        }

        //cur代表当前节点  
        ListNode* cur = head;
        
        //代表当前节点的前一个节点
        ListNode* prev = nullptr;

        //循环的目的是把prev指向第m个节点前的一个节点
        //把cur指向第m个节点
        while (m > 1) 
        {
            prev = cur;
            cur = cur->next;
            if(cur == nullptr)
            {
                return head;
            }
            m--;
            n--;
        }

        //保存prev节点的位置，因为翻转后还需要链接在一起
        ListNode* con = prev;
        prev = nullptr;

        //代表翻转的尾节点指针
        ListNode* tail = cur;

        //代表当前节点的下一个节点，因为当前节点指向已经改变需要保存
        ListNode* third = nullptr;
        while (n > 0) 
        {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        //链接起来
        if (con != nullptr) 
        {
            con->next = prev;
        } 
        else 
        {
            head = prev;
        }

        tail->next = third;
        return head;
    }
};
