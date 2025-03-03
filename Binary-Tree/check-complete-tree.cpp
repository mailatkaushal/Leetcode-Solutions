bool isCompleteTree(TreeNode* root) {
  bool flag=0;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
      auto x=q.front();
      q.pop();
      if (x==NULL) flag=1;
      else {
          if (flag) return 0;
          q.push(x->left);
          q.push(x->right);
      }
  }
  return 1;
}