// Time  : O(n)
// Time  : O(1)

Node *removeLoop(Node *head) {
  Node* fast = head;
  Node* slow = head;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      if (fast == head) {
        while (slow->next != head)
          slow = slow->next;
        slow->next = nullptr;
        break;
      }
      fast = head;
      while (fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = nullptr;
      break;
    }
  }

  return head;
}