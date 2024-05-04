// Time  : O(n)
// Space : O(n)
class Solution{
public:
  vector<int> verticalSum(Node* root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      Node* x = p.first;
      int i = p.second;
      mp[i] += x->data;
      if (x->left) q.push({x->left, i-1});
      if (x->right) q.push({x->right, i+1});
    }
    vector<int> ans;
    for (auto& it : mp) ans.push_back(it.second);
    return ans;
  }
};