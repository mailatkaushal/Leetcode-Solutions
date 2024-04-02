// Time  : O(1)
// Time  : O(n)

class BSTIterator {
public:
  vector<int> in;
  int i = -1;
  BSTIterator(TreeNode* root) {
    while (root) {
      if (root->left == NULL) {
        in.push_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* pre = root->left;
        while (pre->right) 
          pre = pre->right;
        pre->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
  }

  int next() {
    ++i;
    return in[i];
  }
  
  bool hasNext() {
    if (i != in.size()-1)
      return true;
    return false;
  }
};

// Time  : O(1)
// Time  : O(h)

class BSTIterator {
public:
  stack<TreeNode*> st;
  BSTIterator(TreeNode* root) {
    inorder(root);
  }

  void inorder(TreeNode* root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode* t = st.top();
    st.pop();
    inorder(t->right);
    return t->val;
  }

  bool hasNext() {
    return !st.empty();
  }
};