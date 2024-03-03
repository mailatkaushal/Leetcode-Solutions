// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* p = dummy;

    while (n--) 
      p = p->next;

    ListNode* prev = nullptr;
    ListNode* nth = dummy;

    while (p) {
      p = p->next;
      prev = nth;
      nth = nth->next;
    }

    prev->next = nth->next;
    delete(nth);

    return dummy->next;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* p = dummy, *q = dummy;

    while (n--) 
      q = q->next;

    while (q->next != NULL) {
      p = p->next;
      q = q->next;
    }

    ListNode* delNode = p->next;
    p->next = delNode->next;
    delete(delNode);
    
    return dummy->next;
  }
};