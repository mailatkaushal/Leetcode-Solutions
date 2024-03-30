// Time  : O(n)
// Space : O(n)

class Solution {
public:
  unordered_map<int, int> ump;
  TreeNode* f(vector<int>& pre, vector<int>& in, int& i, int lo, int hi) {
    if (lo > hi) 
      return NULL;
    int rootVal = pre[i];
    ++i;
    int j = ump[rootVal];
    TreeNode* root = new TreeNode(rootVal);
    root->left = f(pre, in, i, lo, j-1);
    root->right = f(pre, in, i, j+1, hi);
    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int x = 0; x < n; ++x) 
      ump[inorder[x]] = x;
    int i = 0;
    return f(preorder, inorder, i, 0, n-1);
  }
};