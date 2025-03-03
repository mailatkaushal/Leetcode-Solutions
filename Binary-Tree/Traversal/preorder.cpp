// Time  : O(n)
// Space : O(h)
vector<int> ans;
void preorder(TreeNode* root) {
    if (root==NULL) return;
    ans.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return ans;
}

// Time  : O(n)
// Space : O(n)
vector<int> preorderTraversal(TreeNode* root) {
    if (root==NULL) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        auto x=st.top();
        st.pop();
        ans.push_back(x->val);
        if (x->right) st.push(x->right);
        if (x->left) st.push(x->left);
    }
    return ans;
}

// Morris Traversal
// Time  : O(n)
// Space : O(1)
vector<int> preorderTraversal(TreeNode* root) {
    if (root==NULL) return {};
    vector<int> ans;
    auto x=root;
    while (x) {
        if (x->left==NULL) {
            ans.push_back(x->val);
            x=x->right;
        }
        else {
            auto y=x->left;
            while (y->right && y->right!=x) y=y->right;
            if (y->right==NULL) {
                y->right=x;
                ans.push_back(x->val);
                x=x->left;
            }
            else {
                y->right=NULL;
                x=x->right;
            }
        }
    }
    return ans;
}