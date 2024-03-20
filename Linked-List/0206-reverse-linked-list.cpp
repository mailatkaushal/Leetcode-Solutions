// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
    if (head == nullptr)
      return prev;
    ListNode* next = head->next;
    head->next = prev;
    return reverseList(next, head);
  }
};