// Time  : O(n)
// Space : O(1)

class Solution {
public:
  void sort(Node** head) {
    if ((*head)->next == NULL)
      return;
    Node* p = NULL;
    Node* a = *head;
    Node* b = (*head)->next;
    while (b && b->next) {
      a->next = b->next;
      b->next = p;
      a = a->next;
      p = b;
      b = a->next;
    }
    if (b) {  // even
      a->next = b;
      b->next = p;
    } 
    else  // odd
      a->next = p;
  }
};