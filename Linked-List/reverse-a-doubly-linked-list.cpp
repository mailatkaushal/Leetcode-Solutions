// Time  : O(n)
// Space : O(1)

Node* reverseDLL(Node* head) {
  Node* prev = nullptr;
  while (head) {
    Node* next = head->next;
    head->next = prev;
    head->prev = next;
    prev = head;
    head = next;
  }
  return prev;
}