// Time  : O(n)
// Space : O(n)

class Solution {
public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      TreeNode* newNode = new TreeNode(val);
      newNode->left = root;
      return newNode;
    }
    int d = 0;
    bool rowAdded = false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      ++d;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if (d == depth-1) {
          node->left = new TreeNode(val);
          node->right = new TreeNode(val);
          node->left->left = left;
          node->right->right = right;
          rowAdded = true;
        }
        if (left) q.push(left);
        if (right) q.push(right);
      }
      if (rowAdded == true) break;
    }
    return root;
  }
};