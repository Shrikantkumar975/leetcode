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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* fast=head;
         ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next ;
        }
        int maxi = INT_MIN;
        while(slow != nullptr){
            int a = st.top();
            int b = slow->val;
            maxi = max(a+b , maxi);
            slow = slow->next ;
            st.pop();
        }

        return maxi ;
    }
};