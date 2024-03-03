// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* p = dummy;

    while (n--) 
      p = p->next;

    ListNode* prev = nullptr;
    ListNode* nth = dummy;

    while (p) {
      p = p->next;
      prev = nth;
      nth = nth->next;
    }

    prev->next = nth->next;
    delete(nth);

    return dummy->next;
  }
};