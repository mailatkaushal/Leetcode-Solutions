// Time  : O(n)
// Space : O(n)

vector<int> leftView(Node *root) {
    vector<int> v;
    if (root == nullptr)
        return v;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        bool first = true;
        while (n--) {
            Node* node = q.front();
            q.pop();
            if (first) {
                v.push_back(node->data);
                first = false;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return v;
}