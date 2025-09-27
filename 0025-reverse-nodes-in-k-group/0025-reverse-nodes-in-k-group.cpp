class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }

    // count number of remaining elements and if less than return
    ListNode *curr = head;
    int i = 0;
    while (curr && i < k) {
      curr = curr->next;
      ++i;
    }

    if (i != k) {
      return head;
    }

    ListNode *prev = nullptr;
    curr = head;
    for (i = 0; i < k; ++i) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head->next = reverseKGroup(curr, k);

    return prev;
  }
};