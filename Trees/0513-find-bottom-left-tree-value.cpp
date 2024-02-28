// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int max_depth = -1;
  int bottom_left;

  int findBottomLeftValue(TreeNode* root) {
    f(root, 0);
    return bottom_left;
  }

  void f(TreeNode* root, int depth) {
    if (root == nullptr) 
      return;

    if (depth > max_depth) {
      max_depth = depth;
      bottom_left = root->val;
    }

    f(root->left, depth + 1);
    f(root->right, depth + 1);
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    int bottom_left;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int level_size = q.size();

      for (int i = 0; i < level_size; ++i) {
        TreeNode* node = q.front();
        q.pop();

        if (i == 0) 
          bottom_left = node->val;

        if (node->left) 
          q.push(node->left);
          
        if (node->right)
          q.push(node->right);
      }
    }

    return bottom_left;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    int bottom_left;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        bottom_left = node->val;

        if (node->right) 
          q.push(node->right);

        if (node->left)
          q.push(node->left);
      }
    }

    return bottom_left;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    int bottom_left;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      bottom_left = node->val;

      if (node->right) 
        q.push(node->right);

      if (node->left)
        q.push(node->left);
    }

    return bottom_left;
  }
};