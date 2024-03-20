// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* oddEvenList(ListNode*& head) {
    if (!head || !head->next || !head->next->next)
      return head;

    ListNode* odd = head;
    ListNode* even = head->next;

    ListNode* evenHead = even; 

    while (even && even->next) {
      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
    }

    odd->next = evenHead;

    return head;
  }
};