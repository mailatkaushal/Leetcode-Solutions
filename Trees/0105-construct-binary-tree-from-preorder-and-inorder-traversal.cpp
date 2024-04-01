// Time  : O(n)
// Space : O(n)

class Solution {
public:
  unordered_map<int, int> inMap;
  TreeNode* f(vector<int>& in, int inStart, int inEnd, vector<int>& pre, int preStart, int preEnd) {
    if (inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(pre[preStart]);
    int i = inMap[root->val];
    int left = i - inStart;
    root->left = f(in, inStart, i - 1, pre, preStart + 1, preStart + left);
    root->right = f(in, i + 1, inEnd, pre, preStart + left + 1, preEnd);
    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for (int x = 0; x < n; ++x) 
      inMap[inorder[x]] = x;
    return f(inorder, 0, n-1, preorder, 0, n-1);
  }
};