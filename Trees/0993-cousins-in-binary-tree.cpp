// Time  : O(n)
// Space : O(n)
class Solution {
public:
  bool isCousins(TreeNode* root, int x, int y) {
    TreeNode* a = NULL;
    TreeNode* b = NULL;
    int depa, depb;
    unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = NULL;
    queue<TreeNode*> q;
    q.push(root);
    int d = 0;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        auto r = q.front();
        q.pop();
        if (r->val == x) {
          a = r;
          depa = d;
        }
        if (r->val == y) {
          b = r;
          depb = d;
        }
        if (r->left) {
          parent[r->left] = r;
          q.push(r->left);
        }
        if (r->right) {
          parent[r->right] = r;
          q.push(r->right);
        }
      }
      if (a != NULL && b != NULL) break;
      ++d;
    }
    return depa == depb && parent[a] != parent[b];
  }
};