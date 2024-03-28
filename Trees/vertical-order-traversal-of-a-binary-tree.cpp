// Time  : O(n)
// Space : O(n)

class Solution {    
public:
  vector<int> verticalOrder(Node *root) {
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      mp[x.second].push_back(x.first->data);
      if (x.first->left)
        q.push({x.first->left, x.second-1});
      if (x.first->right)
        q.push({x.first->right, x.second+1});
    }
    vector<int> v;
    for (auto it : mp) 
      for (int& n : it.second) 
        v.push_back(n);
    return v;
  }
};