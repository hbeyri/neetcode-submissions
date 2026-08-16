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

    ListNode* findReverseHead(ListNode* head)
    {
        ListNode* prev_slow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev_slow->next = nullptr;
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head->next)
            return;

        ListNode* reverse_head = findReverseHead(head);
        reverse_head = reverseList(reverse_head);
        ListNode temp;
        ListNode* cur = &temp;
        while(reverse_head)
        {
            if(head)
            {
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
            
            cur->next = reverse_head;
            reverse_head = reverse_head->next;
            cur = cur->next;
        }
        head = temp.next;
    }
};
