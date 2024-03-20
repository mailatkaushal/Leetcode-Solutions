// Time  : O(2n)
// Space : O(n)

Node* sortList(Node *head) {
    vector<int> cnt(3);
    Node* h = head;
    while (h) {
      ++cnt[h->val];
      h = h->next;
    }
    h = head;
    while (h) {
      if (cnt[0]) {
        h->data = 0;
        --cnt[0];
      }
      else if (cnt[1]) {
        h->data = 1;
        --cnt[1];
      }
      else {
        h->data = 2;
        --cnt[2];
      }
      h = h->next;
    }
    return head;
}

// Time  : O(n)
// Space : O(n)

Node* sortList(Node *head) {
    Node* zero = new Node();   
    Node* one = new Node();
    Node* two = new Node();
    Node* z = zero;
    Node* o = one;
    Node* t = two;
    while (head) {
      if (head->data == 0) {
        z->next = new Node(0);
        z = z->next;
      }
      else if (head->data == 1) {
        o->next = new Node(1);
        o = o->next;
      }
      else {
        t->next = new Node(2);
        t = t->next;
      }
      head = head->next;
    }
    z->next = one->next;
    o->next = two->next;
    return zero->next;
}