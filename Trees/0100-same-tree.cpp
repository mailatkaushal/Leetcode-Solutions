// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isSameTree(TreeNode* a, TreeNode* b) {
    queue<TreeNode*> q1, q2;
    q1.push(a);
    q2.push(b);

    while (!q1.empty() && !q2.empty()) {
      TreeNode* node1 = q1.front(); 
      q1.pop();
      TreeNode* node2 = q2.front(); 
      q2.pop();
      
      if (node1 == nullptr && node2 == nullptr) 
        continue;
      else if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
        return false;

      q1.push(node1->left);
      q2.push(node2->left);
      q1.push(node1->right);
      q2.push(node2->right);
    }

    return true;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution:
  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    # both null -> identical
    if not p and not q:
      return True

    # only one null or vals different -> not identical
    if not p or not q or p.val != q.val:
      return False

    return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)