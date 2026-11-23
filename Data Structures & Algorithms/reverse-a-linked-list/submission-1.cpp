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
    ListNode* tail = nullptr;

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        ListNode* new_head = reverseList(head->next);
        if(!tail)
            tail = new_head;
        
        tail->next = head;
        tail = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};
