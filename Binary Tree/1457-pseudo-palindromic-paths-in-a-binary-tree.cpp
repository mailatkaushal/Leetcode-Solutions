// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int pseudoPalindromicPaths (TreeNode* root) {
    vector<int> v(10);
    int res = 0;
    dfs(root, v, res);
    return res;
  }

  void dfs(TreeNode* root, vector<int>& v, int& res) {
    if (!root) 
      return;

    v[root->val]++;

    if (!root->left && !root->right) {
      int oddFreq = 0;
      for (int i = 1; i < 10; ++i) {
        if (v[i] % 2 == 1) 
          ++oddFreq; 
      }
      res += oddFreq <= 1;
    }

    dfs(root->left, v, res);
    dfs(root->right, v, res);

    --v[root->val];
  }
};

// Time: O(n)
// Space: O(1)

class Solution {
public:
  int pseudoPalindromicPaths (TreeNode* root) {
    int res = 0;
    dfs(root, 0, res);
    return res;
  }

  void dfs(TreeNode* root, int tmp, int& res) {
    if (!root) 
      return;

    tmp = tmp ^ (1 << root->val);

    if (!root->left && !root->right) {
      if ((tmp & (tmp-1)) == 0) 
        ++res;
    }

    dfs(root->left, tmp, res);
    dfs(root->right, tmp, res);
  }
};