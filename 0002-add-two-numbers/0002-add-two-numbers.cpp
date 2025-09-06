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
        int sum = 0, carry = 0;
        ListNode *head, *prev;
        head = prev = NULL;
        while (l1 || l2) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            int digit = sum % 10;
            carry = sum >= 10 ? 1 : 0;
            ListNode* temp = new ListNode(digit);
            if (!head) {
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
            }
            prev = temp;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (carry == 1) {
            ListNode* temp = new ListNode(1);
            prev->next = temp;
        }
        return head;
    }
};