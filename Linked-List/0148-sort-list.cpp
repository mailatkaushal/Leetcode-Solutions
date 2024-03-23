// Time  : O(nlogn)
// Space : O(n)

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    vector<int> vals;
    ListNode* h = head;
    while (h) {
      vals.push_back(h->val);
      h = h->next;
    }
    sort(vals.begin(), vals.end());
    h = head;
    for (int& val : vals) {
      h->val = val;
      h = h->next;
    }
    return head;
  }
};

// Time  : O((n+n/2)logn)
// Space : O(1)

class Solution {
public:
  ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode(0);
    ListNode* x = dummy;
    while (a && b) {
      if (a->val <= b->val) {
        x->next = a;
        a = a->next;
      } 
      else {
        x->next = b;
        b = b->next;
      }
      x = x->next;
    }
    if (a) x->next = a;
    else x->next = b;
    return dummy->next;
  }

  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = NULL;
    ListNode* a = sortList(head);
    ListNode* b = sortList(slow);
    return merge(a, b);
  }
};