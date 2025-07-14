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
    int getDecimalValue(ListNode* head) {
        long value = 0;
        ListNode* temp = head;
        int a=0;
        while(temp){
            a++;
            temp=temp->next;
        }
        int p=a-1;
        while(head){
            value+= pow(2,p--)*head->val;
            head = head->next;
        }
        return value;
    }
};