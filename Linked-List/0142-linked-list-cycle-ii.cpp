// Time:  O(n)
// Space: O(n)

class Solution {
public:
  ListNode *detectCycle(ListNode* head) {
    unordered_set<ListNode*> st;

    while (head) {
      if (st.find(head) != st.end()) 
        return head;
      st.insert(head);
      head = head->next;
    }

    return nullptr;
  }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  ListNode *detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (slow == fast) {
        while (head != slow) {
          head = head->next;
          slow = slow->next;
        }
        return slow;
      }
    }

    return nullptr;
  }
};