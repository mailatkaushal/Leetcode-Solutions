// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> post;
  void postorder(TreeNode* root) {
    if (root == NULL)
      return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
    postorder(root);
    return post;
  }
};

// Time  : O(3n)
// Space : O(2n)

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> post;
    if (root == nullptr)
      return post;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
      TreeNode* root = st1.top();
      st1.pop();
      st2.push(root);
      if (root->left)
        st1.push(root->left);
      if (root->right)
        st1.push(root->right);
    }
    while (!st2.empty()) {
      post.push_back(st2.top()->val);
      st2.pop();
    }
    return post;
  }
};

// Time  : O(2n)
// Space : O(n)

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> post;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr || !stk.empty()) {
      if (curr) {
        stk.push(curr);
        curr = curr->left;
      }
      else {
        TreeNode* tmp = stk.top()->right;
        if (tmp == NULL) {
          tmp = stk.top();
          stk.pop();
          post.push_back(tmp->val);
          while (!stk.empty() && tmp == stk.top()->right) {
            tmp = stk.top();
            stk.pop();
            post.push_back(tmp->val);
          }
        }
        else
          curr = tmp;
      }
    }
    return post;
  }
};