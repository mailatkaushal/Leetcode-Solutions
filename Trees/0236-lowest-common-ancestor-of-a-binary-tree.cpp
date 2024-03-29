// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<TreeNode*> patha, pathb;
  void f(TreeNode* root, TreeNode* a, TreeNode* b, vector<TreeNode*>& path) {
    if (root == NULL)
      return;
    path.push_back(root);
    if (root == a)
      patha = path;
    if (root == b)
      pathb = path;
    f(root->left, a, b, path);
    f(root->right, a, b, path);
    path.pop_back();
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    vector<TreeNode*> path;
    f(root, a, b, path);
    TreeNode* lca = NULL;
    for (int i = 0; i < min(patha.size(), pathb.size()); ++i) {
      if (patha[i] != pathb[i])
        break;
      lca = patha[i];
    }
    return lca;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    if (root == NULL || root == a || root == b) return root;
    TreeNode* l = lowestCommonAncestor(root->left, a, b);
    TreeNode* r = lowestCommonAncestor(root->right, a, b);
    if (l == NULL) return r;
    if (r == NULL) return l;
    return root;
  }
};