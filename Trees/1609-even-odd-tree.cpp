// BFS
// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isEvenOddTree(TreeNode* root) {
    // even level -> odd valued nodes in strictly increasing order
    // odd level -> even valued nodes in strictly decreasing order

    queue<TreeNode*> q;
    q.push(root);
    int level = -1;

    while (!q.empty()) {
      ++level;
      int level_size = q.size();

      if ((level & 1) == 0) {  // even level
        TreeNode* prev = q.front();
        q.pop();

        if ((prev->val & 1) == 0) 
          return false;
        
        if (prev->left) 
          q.push(prev->left);
        if (prev->right) 
          q.push(prev->right);

        while (level_size-- > 1) {
          TreeNode* curr = q.front();
          q.pop();

          if ((curr->val & 1) == 0 || prev->val >= curr->val) 
            return false;
          
          if (curr->left) 
            q.push(curr->left);
          if (curr->right) 
            q.push(curr->right);

          prev = curr;
        }
      }

      else {  // odd level
        TreeNode* prev = q.front();
        q.pop();

        if ((prev->val & 1) == 1) 
          return false;
        
        if (prev->left) 
          q.push(prev->left);
        if (prev->right) 
          q.push(prev->right);

        while (level_size-- > 1) {
          TreeNode* curr = q.front();
          q.pop();

          if ((curr->val & 1) == 1 || prev->val <= curr->val) 
            return false;
          
          if (curr->left) 
            q.push(curr->left);
          if (curr->right) 
            q.push(curr->right);

          prev = curr;
        }
      }
    }

    return true;
  }
};

// minimised code
// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool even = false;

    while (!q.empty()) {
      even = !even;
      int n = q.size();
      int prev = even == true ? INT_MIN : INT_MAX;

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        if (even && ((node->val & 1) == 0 || prev >= node->val))
          return false;
        if (!even && ((node->val & 1) == 1 || prev <= node->val))
          return false;

        prev = node->val;

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      } 
    }

    return true;
  }
};