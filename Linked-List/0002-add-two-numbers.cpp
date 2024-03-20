// Time  : O(max(m, n))
// Time  : O(max(m, n))

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* h = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      h->next = new ListNode(sum % 10);
      h = h->next;
      carry = sum / 10;
    }

    return dummy->next;
  }
};