// Time  : O(3n)
// Time  : O(1)

Node* reverseList(Node* head) {
  Node* prev = nullptr;
  while (head) {
    Node* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

Node* addOne(Node *head) {
  Node* reverseHead = reverseList(head);
  Node* h = reverseHead;
  int carry = 1;
  while (h) {
    int sum = carry + h->data;
    h->data = sum % 10;
    carry = sum / 10;
    h = h->next;
  }
  if (carry) {
    Node* node = new Node(carry);
    node->next = reverseList(reverseHead);
    return node;
  }
  return reverseList(reverseHead);
}