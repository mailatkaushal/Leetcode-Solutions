// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    vector<int> res;
    int streak = 0;
    int maxStreak = 0;
    int num = -1e5-1;
    while (root) {
      if (root->left == NULL) {
        if (num == root->val) ++streak;
        else { num = root->val; streak = 1; }
        if (streak > maxStreak) { res = {}; maxStreak = streak; }
        if (streak == maxStreak) res.push_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* pre = root->left;
        while (pre->right)
          pre = pre->right;
        pre->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    return res;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    vector<int> res;
    int streak = 0;
    int maxStreak = 0;
    int num = -1e5-1;
    while (root) {
      if (root->left == NULL) {
        if (num == root->val) ++streak;
        else { num = root->val; streak = 1; }
        if (streak > maxStreak) { res = {}; maxStreak = streak; }
        if (streak == maxStreak) res.push_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* pre = root->left;
        while (pre->right)
          pre = pre->right;
        pre->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    return res;
  }
};