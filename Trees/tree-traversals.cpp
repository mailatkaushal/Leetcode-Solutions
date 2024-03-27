// Time  : O(3n)
// Space : O(3n)

vector<vector<int>> getTreeTraversal(TreeNode *root){
  vector<int> pre;
  vector<int> in;
  vector<int> post;
  stack<pair<TreeNode*, int>> stk;
  stk.push({root, 1});
  while (!stk.empty()) {
    auto p = stk.top();
    stk.pop();
    if (p.second == 1) {
      pre.push_back(p.first->data);
      ++p.second;
      stk.push(p);
      if (p.first->left) 
        stk.push({p.first->left, 1});
    }
    else if (p.second == 2) {
      in.push_back(p.first->data);
      ++p.second;
      stk.push(p);
      if (p.first->right)
        stk.push({p.first->right, 1});
    }
    else 
      post.push_back(p.first->data);
  }
  return {in, pre, post};
}