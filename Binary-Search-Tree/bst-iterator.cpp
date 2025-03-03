// Time  : O(1)
// Space : O(h)
stack<TreeNode*> st;
BSTIterator(TreeNode* root) {
    inorder(root);
}
void inorder(TreeNode* root) {
    while (root) {
        st.push(root);
        root=root->left;
    }
}
int next() {
    TreeNode* t=st.top(); st.pop();
    inorder(t->right);
    return t->val;
}
bool hasNext() {
    return !st.empty();   
}