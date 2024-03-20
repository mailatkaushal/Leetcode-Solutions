// Time  : O(n)
// Space : O(1)

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    if (fast)
      slow = slow->next;
    while (slow) {
      if (prev->val != slow->val)
        return false;
      prev = prev->next;
      slow = slow->next;
    }
    return true;
  }
};