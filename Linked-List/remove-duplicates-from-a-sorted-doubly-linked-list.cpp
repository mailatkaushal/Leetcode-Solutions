// Time  : O(n)
// Space : O(1)

Node* removeDuplicates(Node* head) {
  Node* h = head;
  while (h && h->next) {
    Node* i = h->next;
    while (i && i->data == h->data) {
      i = i->next;
    }
    h->next = i;
    if (i)
      i->prev = h;
    h = h->next;
  }
  return head;
}