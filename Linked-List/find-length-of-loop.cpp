// Time  : O(n)
// Space : O(n)

#include <bits/stdc++.h>
int lengthOfLoop(Node *head) {
  unordered_map<Node*, int> ump;
  Node* h = head;
  for (int i = 1; h; ++i) {
    if (ump.find(h) != ump.end())
      return i - ump[h];
    ump[h] = i;
    h = h->next;
  }
  return 0;
}