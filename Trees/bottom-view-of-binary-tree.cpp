// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> bottomView(Node* root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      mp[x.second] = x.first->data;
      if (x.first->left) 
        q.push({x.first->left, x.second - 1});
      if (x.first->right) 
        q.push({x.first->right, x.second + 1});
    }
    vector<int> b;
    for (auto it : mp) 
      b.push_back(it.second);
    return b;
  }
};