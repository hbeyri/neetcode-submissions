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
    ListNode* reverse(ListNode* head)
    {
        ListNode* node = head;
        if(!node || !node->next)
            return node;

        ListNode* prev = nullptr;
        while(node)
        {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev_head = slow->next;
        slow->next = nullptr;

        rev_head = reverse(rev_head);
        ListNode dummy;
        ListNode* node = &dummy;
        while(head || rev_head)
        {
            if(head)
            {
                node->next = head;
                head = head->next;
                node = node->next;
            }
            if(rev_head)
            {
                node->next = rev_head;
                rev_head = rev_head->next;
                node = node->next;
            }
        }
    }


};
