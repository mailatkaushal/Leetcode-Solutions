// Time  : O(n)
// Space : O(n)
vector<int> levelOrder(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        ans.push_back(x->data);
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
    }
    return ans;
}