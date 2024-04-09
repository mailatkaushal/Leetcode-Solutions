// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = NULL;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if (node->left == NULL && node->right == NULL) {
        int i = 0;
        TreeNode* cur = node;
        int num = 0;
        while (cur) {
          num += cur->val * pow(10, i);
          cur = parent[cur];
          ++i;
        }
        sum += num;
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
    return sum;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int sumNumbers(TreeNode* root, int sum = 0) {
    if (root == NULL) return 0;
    sum = sum*10 + root->val;
    if (root->left == NULL && root->right == NULL) return sum;
    int l = sumNumbers(root->left, sum);
    int r = sumNumbers(root->right, sum);
    return l + r;
  }
};