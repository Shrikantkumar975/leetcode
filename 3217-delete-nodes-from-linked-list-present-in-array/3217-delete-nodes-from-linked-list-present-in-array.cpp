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
    // bool present(int val,vector<int>& nums){
    //     for(int a: nums){
    //         if(a==val) return true;
    //     }
    //     return false;
    // }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> S(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr){
            if(S.count(curr->val)){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                prev = curr;
                curr =curr->next;
            }
        }
        return dummy->next;
    }
};