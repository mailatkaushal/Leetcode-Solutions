// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* h = head;
    while (h && h->next) {
      ListNode* i = h->next;
      while (i && h->val == i->val)
        i = i->next;
      h->next = i;
      h = h->next;
    }
    return head;
  }
};