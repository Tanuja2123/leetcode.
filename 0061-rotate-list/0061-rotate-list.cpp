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
    ListNode* helper(ListNode* cutpt, int cnt) {
        while (cutpt->next != NULL && cnt - 1 > 0) {
            cutpt = cutpt->next;
            cnt--;
        }
        return cutpt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 1;
        // add the base case
        if (head == NULL || head->next == NULL)
            return head;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        k = k % len;

        if (k == 0)
            return head;

        temp->next = head;
        ListNode* last = helper(head, len - k);
        ListNode* newhead = last->next;
        last->next = NULL;
        return newhead;
    }
};