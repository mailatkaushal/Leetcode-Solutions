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

// Time  : O(n)
// Space : O(1)

int lengthOfLoop(Node *head) {
  Node* fast = head;
  Node* slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      int len = 1;
      slow = slow->next;
      while (slow != fast) {
        ++len;
        slow = slow->next;
      }
      return len;
    }
  }
  return 0;
}