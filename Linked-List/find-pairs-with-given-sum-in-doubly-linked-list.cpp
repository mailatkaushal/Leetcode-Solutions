// Time  : O(n^2)
// Space : O(m) - Where m is the number of pairs

vector<pair<int, int>> findPairs(Node* head, int k) {
  vector<pair<int, int>> res;
  for (Node* h = head; h->next; h = h->next) {
    for (Node* hh = h->next; hh; hh = hh->next) {
      if (h->data + hh->data == k) 
        res.push_back({h->data, hh->data});
    }
  }
  return res;
}

// Time  : O(n)
// Space : O(m) - Where m is the number of pairs

vector<pair<int, int>> findPairs(Node* head, int k) {
  vector<pair<int, int>> res;
  Node* h = head;
  Node* t = head;
  while (t->next) 
    t = t->next;
  while (h->data < t->data) {
    if (h->data + t->data == k) {
      res.push_back({h->data, t->data});
      h = h->next;
      t = t->prev;
    }
    else if (h->data + t->data < k)
      h = h->next;
    else 
      t = t->prev;
  }
  return res;
}