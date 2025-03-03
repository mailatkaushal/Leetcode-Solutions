// Time  : O(n)
// Space : O(n)
vector<int> diagonal(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        while (x) {
            ans.push_back(x->data);
            if (x->left) q.push(x->left);
            x=x->right;
        }
    }
    return ans;
}