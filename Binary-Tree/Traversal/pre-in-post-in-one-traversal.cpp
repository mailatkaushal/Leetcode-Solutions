// Time  : O(3n)
// Space : O(3n)
vector<vector<int>> getTreeTraversal(TreeNode* root) {
  vector<int> pre,in,post;
  stack<pair<TreeNode*,int>> st;
  st.push({root,1});
  while (!st.empty()) {
      auto p=st.top();
      st.pop();
      if (p.second==1) {
          pre.push_back(p.first->data);
          ++p.second;
          st.push(p);
          if (p.first->left) st.push({p.first->left,1});
      }
      else if (p.second==2) {
          in.push_back(p.first->data);
          ++p.second;
          st.push(p);
          if (p.first->right) st.push({p.first->right,1});
      }
      else post.push_back(p.first->data);
  }
  return {in,pre,post};
}