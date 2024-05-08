// Time  : O(n)
// Space : O(1)
class Solution {
public:
  vector<int> findMode(TreeNode* x) {
    // mode - the most frequently occurred element
    vector<int> ans;
    int streak = 0;
    int maxStreak = 0;
    int i = INT_MIN;
    while (x) {
      if (x->left == NULL) {
        if (i == x->val) ++streak;
        else { i = x->val; streak = 1; }
        if (streak > maxStreak) { maxStreak = streak; ans = {}; }
        if (streak == maxStreak) ans.push_back(i);
        x = x->right;
      }
      else {
        TreeNode* y = x->left;
        while (y->right) y = y->right;
        y->right = x;
        TreeNode* z = x;
        x = x->left;
        z->left = NULL;
      }
    }
    return ans;
  }
};