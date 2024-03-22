// Time  : O(2kn + knlog(kn)) - Where k is the number lists & n is the average size of each list 
// Space : O(2nk)

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> vals;
    for (ListNode* h : lists) {
      while (h) {
        vals.push_back(h->val);
        h = h->next;
      }
    }
    sort(vals.begin(), vals.end());
    ListNode* dummy = new ListNode();
    ListNode* h = dummy;
    for (int& n : vals) {
      h->next = new ListNode(n);
      h = h->next;
    }
    return dummy->next;
  }
};

// Time  : O(2n+3n+4n+..+kn) = O(n+2n+3n+..+(k-1)n) = O((k-1)kn/2) ~ O(kkn)
// Space : O(1)

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0)
      return nullptr;
    for (int i = 1; i < n; ++i) 
      lists[i] = mergeTwoLists(lists[i-1], lists[i]);
    return lists[n-1];
  }

  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode();
    ListNode* h = dummy;
    while (a && b) {
      if (a->val <= b->val) {
        h->next = a;
        a = a->next;
      }
      else {
        h->next = b;
        b = b->next;
      }
      h = h->next;
    }
    if (a) h->next = a;
    else h->next = b;
    return dummy->next;
  }
};

// Time  : O(klogk + 3knlogk) ~ O(knlogk)
// Space : O(k)

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for (ListNode* h : lists) {
      if (h)
        pq.push({h->val, h});
    }
    if (pq.empty()) return nullptr;
    ListNode* dummy = new ListNode();
    ListNode* h = dummy;
    while (!pq.empty()) {
      auto mi = pq.top();
      pq.pop();
      if (mi.second->next)
        pq.push({mi.second->next->val, mi.second->next});
      h->next = mi.second;
      h = h->next;
    }
    return dummy->next;
  }
};