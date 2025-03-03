// Time  : O(n)
// Space : O(h)
vector<int> ans;
void inorder(TreeNode* root) {
    if (root==NULL) return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
} 
vector<int> inorderTraversal(TreeNode* root) {
    inorder(root);
    return ans;
}

// Time  : O(n)
// Space : O(n)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    while (1) {
        if (root) {
            st.push(root);
            root=root->left;
        }
        else {
            if (st.empty()) break;
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            root=root->right;
        }
    }
    return ans;
}

// Morris Traversal
// Time  : O(n)
// Space : O(1)
vector<int> inorderTraversal(TreeNode* root) {
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
                x=x->left;
            }
            else {
                y->right=NULL;
                ans.push_back(x->val);
                x=x->right;
            }
        }
    }
    return ans;
}