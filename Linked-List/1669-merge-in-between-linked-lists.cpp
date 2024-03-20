// Time  : O(n)
// Ṣpace : O(1)

class Solution {
public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* prev_a = list1; 
    ListNode* after_b = list1;

    for (int i = 1; i <= b + 1; ++i) {
      if (i <= a - 1) prev_a = prev_a->next;
      after_b = after_b->next;
    }

    prev_a->next = list2;
    
    while (list2->next) 
      list2 = list2->next;

    list2->next = after_b;

    return list1;
  }
};