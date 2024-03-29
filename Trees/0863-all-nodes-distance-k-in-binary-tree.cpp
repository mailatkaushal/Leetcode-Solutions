// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;  // node -> parent
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node->left) {
        parent[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parent[node->right] = node;
        q.push(node->right);
      }
    }
    q.push(target);
    unordered_set<TreeNode*> visited;
    visited.insert(target);
    int dis = 1;
    while (!q.empty() && dis <= k) {
      ++dis;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left && visited.find(node->left) == visited.end()) {
          q.push(node->left);
          visited.insert(node->left);
        }
        if (node->right && visited.find(node->right) == visited.end()) {
          q.push(node->right);
          visited.insert(node->right);
        }
        if (parent[node] && visited.find(parent[node]) == visited.end()) {
          q.push(parent[node]);
          visited.insert(parent[node]);
        }
      }
    }
    vector<int> v;
    while (!q.empty()) {
      v.push_back(q.front()->val);
      q.pop();
    }
    return v;
  }
};