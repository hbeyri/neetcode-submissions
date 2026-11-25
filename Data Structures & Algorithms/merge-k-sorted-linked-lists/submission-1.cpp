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
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode dummy;
        ListNode* cur = &dummy;
        while(a || b)
        {
            if(!b || (a && b && a->val < b->val))
            {
                cur->next = a;
                a = a->next;
            }
            else
            {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end)
    {
        if(start == end)
            return lists[start];

        int mid = (end + start) / 2;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid+1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return merge(lists, 0, lists.size()-1);
    }
};
