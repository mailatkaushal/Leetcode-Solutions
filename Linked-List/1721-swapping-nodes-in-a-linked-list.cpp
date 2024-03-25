// Time  : O(n)
// Time  : O(1)

class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* a = head;
    while (--k) 
      a = a->next;
    ListNode* c = a;
    ListNode* b = head;
    while (c->next) {
      c = c->next;
      b = b->next;
    }
    swap(a->val, b->val);
    return head;
  }
};