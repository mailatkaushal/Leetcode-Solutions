// Time  : O(2n)
// Space : O(1)

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    ListNode* tail = head;
    int len = 1;
    while (tail->next) {
      ++len;
      tail = tail->next;
    }
    k = k % len;
    if (k == 0) return head;
    tail->next = head;
    ListNode* newTail = head;
    for (int i = 1; i < len - k; ++i)
      newTail = newTail->next;
    head = newTail->next;
    newTail->next = nullptr;
    return head;
  }
};