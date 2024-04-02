// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> a;
    TreeNode* cur = root1;
    stack<TreeNode*> st;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      a.push_back(cur->val);
      cur = cur->right;
    }
    vector<int> b;
    cur = root2;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      b.push_back(cur->val);
      cur = cur->right;
    }
    int x = a.size();
    int y = b.size();
    vector<int> c(x+y);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < x && j < y) {
      if (a[i] <= b[j])
        c[k++] = a[i++];
      else 
        c[k++] = b[j++];
    }
    while (i < x) c[k++] = a[i++];
    while (j < y) c[k++] = b[j++];
    return c;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> v;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* cur1 = root1;
    TreeNode* cur2 = root2;
    while (cur1 || !st1.empty() || cur2 || !st2.empty()) {
      while (cur1) {
        st1.push(cur1);
        cur1 = cur1->left;
      }
      while (cur2) {
        st2.push(cur2);
        cur2 = cur2->left;
      }
      if (st1.empty()) {
        cur2 = st2.top();
        st2.pop();
        v.push_back(cur2->val);
        cur2 = cur2->right;
      }
      else if (st2.empty()) {
        cur1 = st1.top();
        st1.pop();
        v.push_back(cur1->val);
        cur1 = cur1->right;
      }
      else {
        if (st1.top()->val <= st2.top()->val) {
          cur1 = st1.top();
          st1.pop();
          v.push_back(cur1->val);
          cur1 = cur1->right;
        }
        else {
          cur2 = st2.top();
          st2.pop();
          v.push_back(cur2->val);
          cur2 = cur2->right;
        }
      }
    }
    return v;
  }
};