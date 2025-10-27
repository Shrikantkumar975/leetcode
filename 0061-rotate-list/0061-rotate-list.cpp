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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Find length
        int l = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            l++;
        }

        // Step 2: Reduce k
        k = k % l;
        if (k == 0)
            return head;

        // Step 3: Move fast k steps ahead
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        // Step 4: Move both until fast reaches the end
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5: Rotate the list
        fast->next = head;    // Connect tail to head
        head = slow->next;    // New head
        slow->next = nullptr; // Break the link

        return head;
    }
};