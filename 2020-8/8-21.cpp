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
