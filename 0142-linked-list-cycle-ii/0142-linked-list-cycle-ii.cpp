/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int count=0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            while(slow==fast){
                ListNode* temp = head;
                while(slow!=temp){
                    slow=slow->next;
                    temp=temp->next;
                    count++;
                }
                return temp;
            }

        }
        return nullptr;

    }
};