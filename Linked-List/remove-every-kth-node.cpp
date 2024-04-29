// Time  : O(n)
// Space : O(1)
class Solution {
public:
  Node* deleteK(Node* head, int k) {
    if (k == 1) return NULL;
    int x = 2;
    Node* prev = head;
    Node* curr = head->next;
    while (curr) {
      if (x % k == 0) {
        prev->next = curr->next;
        curr = curr->next;
      }
      else {
        prev = prev->next;
        curr = curr->next;
      }
      ++x;
    }
    return head;
  }
};