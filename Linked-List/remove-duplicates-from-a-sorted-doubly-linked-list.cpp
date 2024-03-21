// Time  : O(n)
// Space : O(1)

Node* removeDuplicates(Node* head) {
  Node* h = head;
  while (h->next) {
    Node* i = h;
    while (i && i->data == h->data) 
      i = i->next;
    // if i reaches unequal node
    if (i != nullptr) {
      h->next = i;
      i->prev = h;
      h = h->next;
    }
    // if i reaches nullptr
    else 
      h->next = nullptr;
  }
  return head;
}