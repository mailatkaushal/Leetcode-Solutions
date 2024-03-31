// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        v.push_back(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* prev = cur->left;
        while (prev->right && prev->right != cur) 
          prev = prev->right;
        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        }
        else {
          prev->right = NULL;
          v.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    int n = v.size();
    return v[k-1];
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    int kthmin;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        ++cnt;
        if (cnt == k) {
          kthmin = cur->val;
          break;
        }
        cur = cur->right;
      }
      else {
        TreeNode* prev = cur->left;
        while (prev->right) 
          prev = prev->right;
        prev->right = cur;
        TreeNode* tmp = cur;
        cur = cur->left;
        tmp->left = NULL;
      }
    }
    return kthmin;
  }
};