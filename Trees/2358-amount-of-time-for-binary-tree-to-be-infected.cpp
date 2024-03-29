// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int amountOfTime(TreeNode* root, int x) {
    TreeNode* inf = NULL;
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (inf == NULL && node->val == x) 
        inf = node;
      if (node->left) {
        parent[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parent[node->right] = node;
        q.push(node->right);
      }
    }
    q.push(inf);
    unordered_set<TreeNode*> st;
    st.insert(inf);
    int t = -1;
    while (!q.empty()) {
      ++t;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left && st.find(node->left) == st.end()) {
          q.push(node->left);
          st.insert(node->left);
        }
        if (node->right && st.find(node->right) == st.end()) {
          q.push(node->right);
          st.insert(node->right);
        }
        if (parent[node] && st.find(parent[node]) == st.end()) {
          q.push(parent[node]);
          st.insert(parent[node]);
        }
      }
    }
    return t;
  }
};