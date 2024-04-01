// Time  : O(n)
// Space : O(n)

class Solution {
public:
  unordered_map<int, int> inMap;
  TreeNode* f(vector<int>& in, int inStart, int inEnd, vector<int>& post, int postStart, int postEnd) {
    if (inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(post[postEnd]);
    int i = inMap[root->val];
    int left = i - inStart;
    root->left = f(in, inStart, i - 1, post, postStart, postStart + left - 1);
    root->right = f(in, i + 1, inEnd, post, postStart + left, postEnd - 1);
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    for (int x = 0; x < n; ++x) 
      inMap[inorder[x]] = x;
    return f(inorder, 0, n-1, postorder, 0, n-1);
  }
};