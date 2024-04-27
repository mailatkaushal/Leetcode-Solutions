// Time  : O((n+n/2)logn)
// Space : O(1)
class Solution {
public:
  Node* merge(Node* a, Node* b) {
    Node* dummy = new Node(0);
    Node* x = dummy;
    while (a && b) {
      if (a->data <= b->data) {
        x->next = a;
        a->prev = x;
        a = a->next;
      }
      else {
        x->next = b;
        b->prev = x;
        b = b->next;
      }
      x = x->next;
    }
    while (a) {
      x->next = a;
      a->prev = x;
      x = x->next;
      a = a->next;
    }
    while (b) {
      x->next = b;
      b->prev = x;
      x = x->next;
      b = b->next;
    }
    dummy = dummy->next;
    dummy->prev = NULL;
    return dummy;
  }
  // Function to sort the given doubly linked list using Merge Sort.
  struct Node* sortDoubly(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = NULL;
    slow->prev = NULL;
    Node* x = sortDoubly(head);
    Node* y = sortDoubly(slow);
    return merge(x, y);
  }
};