// Time  : O(2n)
// SPace : O(1)

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* groupPrev= dummy;
    while (1) {
      ListNode* kth = groupPrev;
      int cnt = 0;
      while (kth && cnt < k) {
        kth = kth->next;
        ++cnt;
      }
      if (!kth)
        break;
      ListNode* groupNext = kth->next;
      ListNode* prev = groupNext;
      ListNode* h = groupPrev->next;
      while (h != groupNext) {
        ListNode* next = h->next;
        h->next = prev;
        prev = h;
        h = next;
      }
      ListNode* tmp = groupPrev->next;
      groupPrev->next = kth;
      groupPrev = tmp;
    }
    return dummy->next;
  }
};