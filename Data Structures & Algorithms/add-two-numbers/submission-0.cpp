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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l1;
        if(!l2) return l2;

        ListNode ret;
        ListNode* prev_sum = &ret;
        int carry = 0;
        while(l1 || l2)
        {
            int sum = carry;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;
            carry = sum / 10;
            int rem = sum % 10;
            ListNode* new_node = new ListNode(rem);
            prev_sum->next = new_node;
            prev_sum = new_node;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if(carry != 0)
        {
            prev_sum->next = new ListNode(carry);
        }

        return ret.next;
    }
};
