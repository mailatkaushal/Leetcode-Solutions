// Time  : O(n)
// Space : O(1)

class Solution {
public:
  Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
      newNode->next = newNode;
      head = newNode;
    }
    else if (data <= head->data) {
      Node* t = head;
      while (t->next != head)
        t = t->next;
      t->next = newNode;
      newNode->next = head;
      head = newNode;
    }
    else {
      Node* a = head;
      while (a->next != head && data > a->next->data) 
        a = a->next;
      newNode->next = a->next;
      a->next = newNode;
    }
    return head;
  }
};