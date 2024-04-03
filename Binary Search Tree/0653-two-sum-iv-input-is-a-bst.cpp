// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> st;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        if (st.find(k - cur->val) != st.end())
          return true;
        st.insert(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* pre = cur->left;
        while (pre->right)
          pre = pre->right;
        pre->right = cur;
        TreeNode* tmp = cur;
        cur = cur->left;
        tmp->left = NULL;
      }
    }
    return false;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> A;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        A.push_back(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* pre = cur->left;
        while (pre->right)
          pre = pre->right;
        pre->right = cur;
        TreeNode* tmp = cur;
        cur = cur->left;
        tmp->left = NULL;
      }
    }
    int lo = 0;
    int hi = A.size()-1;
    while (lo < hi) {
      if (A[lo] + A[hi] < k) ++lo;
      else if (A[lo] + A[hi] > k) --hi;
      else return true;
    }
    return false;
  }
};