// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* node = p.first;
      int x = p.second.first;
      int y = p.second.second;
      mp[x][y].insert(node->val);
      if (node->left) 
        q.push({node->left, {x-1, y+1}});
      if (node->right) 
        q.push({node->right, {x+1, y+1}});
    }
    vector<vector<int>> vv;
    for (auto& a : mp) {
      vector<int> v;
      for (auto& b : a.second) 
        v.insert(v.end(), b.second.begin(), b.second.end());
      vv.push_back(v);
    }
    return vv;
  }
};