// Time:  O(n)
// Space: O(n)

class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> st;

    while (head) {
      if (st.find(head) != st.end())
        return true;
      st.insert(head);
      head = head->next;
    }

    return false;
  }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  bool hasCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (slow == fast)
        return true;
    }

    return false;
  }
};