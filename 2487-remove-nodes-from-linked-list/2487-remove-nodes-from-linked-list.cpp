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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* nextNext = nullptr;
        ListNode* prev = nullptr;

        while (curr) {
            nextNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNext;
        }

        head = prev;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next)
            return head;

        head = reverseList(head);

        ListNode* curr = head;
        ListNode* prev = nullptr;

        prev = head;
        curr = head->next;

        while (curr) {
            if (curr->val < prev->val) {
                prev->next = prev->next->next;
                curr = curr->next;
            } else if (curr->val == prev->val) {
                curr = curr->next;

            } else {
                prev = curr;
            }
        }

        head = reverseList(head);

        return head;
    }
};