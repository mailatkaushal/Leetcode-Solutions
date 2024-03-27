// Time  : O(2n)
// Space : O(2n)

class Solution {
public:
  Node* copyRandomList(Node* head) {
    Node* h = head;
    Node* dummy = new Node(0);
    Node* x = dummy;
    unordered_map<Node*, Node*> ump;
    while (h) {
      Node* newNode = new Node(h->val);
      ump[h] = newNode;
      x->next = newNode;
      x = newNode;
      h = h->next;
    }
    h = head;
    x = dummy->next;
    while (h) {
      x->random = ump[h->random];
      h = h->next;
      x = x->next;
    }
    return dummy->next;
  }
};

// Time  : O(3n)
// Space : O(1)

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == NULL)
      return head;
    Node* x = head;
    while (x) {
      Node* next = x->next;
      Node* newNode = new Node(x->val);
      x->next = newNode;
      newNode->next = next;
      x = next;
    }
    x = head;
    while (x) {
      if (x->random == NULL)
        x->next->random = NULL;
      else 
        x->next->random = x->random->next;
      x = x->next->next;
    }
    Node* a = head;
    Node* b = a->next;
    Node* newHead = b;
    while (b) {
      a->next = b->next;
      if (b->next)
        b->next = b->next->next;
      a = a->next;
      b = b->next;
    }
    return newHead;
  }
};