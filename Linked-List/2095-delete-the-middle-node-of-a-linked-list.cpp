// Time  : O(n/2)
// Space : O(1)

class Solution {
public:
  ListNode* deleteMiddle(ListNode*& head) {
    if (!head->next)
      return nullptr;
    ListNode* fast = head->next->next;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};