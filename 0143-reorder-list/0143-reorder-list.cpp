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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        while(temp!=nullptr && temp->next != nullptr){
            ListNode* last = temp;
            ListNode* prev = nullptr;
            while(last->next){
                prev=last;
                last=last->next;
            }
            
            prev->next =nullptr;
            ListNode* currNext = temp->next;
            temp->next = last;
            last->next=currNext;
            temp=currNext;
        }
    }
};