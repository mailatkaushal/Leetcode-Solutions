// Time  : O(n)
// Space : O(h)

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
  bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (root == NULL) return true;
    if ((min == NULL || min->val < root->val) && (max == NULL || root->val < max->val)) 
      return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    return false;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    vector<int> v;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        v.push_back(cur->val);
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
    for (int i = 1; i < v.size(); ++i) 
      if (v[i-1] >= v[i]) 
        return false;
    return true;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    int i = 0;
    int pre_val = 0;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        if (i > 0 && pre_val >= cur->val) return false;
        pre_val = cur->val;
        ++i;
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
    return true;
  }
};