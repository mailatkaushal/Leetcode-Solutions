// Time  : O(n)
// Space : O(1)
class Solution {
public:
  void rearrange(struct Node* head) {
    Node* p = NULL;
    Node* a = head;
    Node* b = head->next;
    while (b && b->next) {
      a->next = b->next;
      b->next = p;
      p = b;
      a = a->next;
      b = a->next;
    }
    b ? b->next = p : a->next = p;
  }
};