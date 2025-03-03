vector<int> topView(Node* root) {
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        if (mp.find(x.second)==mp.end()) mp[x.second]=x.first->data;
        if (x.first->left) q.push({x.first->left,x.second-1});
        if (x.first->right) q.push({x.first->right,x.second+1});
    }
    vector<int> ans;
    for (auto x:mp) ans.push_back(x.second);
    return ans;
}