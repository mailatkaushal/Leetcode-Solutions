// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int pairSum(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast) {
      fast = fast->next->next;
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    int ma = 1;
    while (slow) {
      ma = max(ma, prev->val + slow->val);
      prev = prev->next;
      slow = slow->next;
    }
    return ma;
  }
};