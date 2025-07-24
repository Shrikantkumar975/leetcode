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

        while(curr){
            nextNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNext;
        }

        head = prev;
        return head;
    }
};