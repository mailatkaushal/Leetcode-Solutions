// Time  : O(m + n)
// Space : O(m)

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> st;
    ListNode* a = headA;
    while (a) {
      st.insert(a);
      a = a->next;
    }
    ListNode* b = headB;
    while (b) {
      if (st.find(b) != st.end())
        return b;
      b = b->next;
    }
    return nullptr;
  }
};

// Time  : O(2max(m, n))
// Space : O(1)

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    int lenA = 0, lenB = 0;
    while (a) {
      ++lenA;
      a = a->next;
    }
    while (b) {
      ++lenB;
      b = b->next;
    }
    a = headA;
    b = headB;
    int diff = abs(lenA - lenB);
    if (lenA > lenB) {
      while (diff--) 
        a = a->next;
    }
    else {
      while (diff--)
        b = b->next;
    }
    while (a != b) {
      a = a->next;
      b = b->next;
    }
    return a;
  }
};

// Time  : O(m + n)
// Space : O(1)

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
      a = a != nullptr ? a->next : headB;
      b = b != nullptr ? b->next : headA;
    }
    return a;
  }
};