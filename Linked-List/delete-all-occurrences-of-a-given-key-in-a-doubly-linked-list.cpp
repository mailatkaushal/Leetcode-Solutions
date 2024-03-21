// Time  : O(n)
// Space : O(1)

Node* deleteAllOccurrences(Node* head, int k) {
  Node* dummy = new Node(0, head, nullptr);
  head->prev = dummy;
  Node* curr = head;
  while (curr) {
    if (curr->data == k) {
      curr->prev->next = curr->next;
      if (curr->next) 
        curr->next->prev = curr->prev;
    }
    curr = curr->next;
  }
  if (dummy->next) 
    dummy->next->prev = nullptr;
  return dummy->next;
}