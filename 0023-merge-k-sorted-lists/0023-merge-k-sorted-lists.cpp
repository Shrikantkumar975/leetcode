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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* v1, ListNode* v2) { return v1->val > v2->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp) {
                pq.push(temp);
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            temp = temp->next;
        }

        return dummy->next;
    }
};