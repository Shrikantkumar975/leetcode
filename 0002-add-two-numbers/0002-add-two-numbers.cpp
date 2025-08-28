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
        ListNode* Dummy = new ListNode(0);
        ListNode* tail = Dummy;
        
        int carry = 0;

        while(l1 || l2 || carry){
            int a = 0;

            if(l1){
                a+=l1->val;
                l1=l1->next;
            }

            if(l2){
                a+=l2->val;
                l2=l2->next;
            }

            a+=carry;

            ListNode* newNode = new ListNode(a%10);
            tail->next = newNode;
            tail = newNode;

            carry = a/10;
        }
        

        return Dummy->next;
    }
};