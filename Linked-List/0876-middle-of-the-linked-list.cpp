// Time  : O(n + n/2)
// Space : O(1)

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    int cnt = 0;
    ListNode* h = head;
    while (h) {
      ++cnt;
      h = h->next;
    }
    int midNode = (cnt / 2) + 1;
    h = head;
    for (int i = 1; h; ++i) {
      if (i == midNode)
        return h;
      h = h->next;
    }
    return nullptr;
  }
};

// Time  : O(n/2)
// Space : O(1)

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head, *slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }
};