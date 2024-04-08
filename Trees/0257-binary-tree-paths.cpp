// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> vs;
    unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = NULL;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if (node->left == NULL && node->right == NULL) {
        TreeNode* cur = node;
        vector<int> v;
        while (cur) {
          v.push_back(cur->val);
          cur = parent[cur];
        }
        int n = v.size();
        string s;
        s += to_string(v[n-1]);
        for (int i = n-2; i >= 0; --i) {
          s += "->" + to_string(v[i]);
          cur = parent[cur];
        }
        vs.push_back(s);
      }
      if (node->right) {
        parent[node->right] = node;
        st.push(node->right);
      }
      if (node->left) {
        parent[node->left] = node;
        st.push(node->left);
      }
    }
    return vs;
  }
};