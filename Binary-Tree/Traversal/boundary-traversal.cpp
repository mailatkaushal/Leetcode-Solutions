// Time  : O(n)
// Space : O(n)
vector<int> ans;
void left(Node* root) {
    if (root == NULL) return;
    if (root->left) {
        ans.push_back(root->data);
        left(root->left);
    }
    else if (root->right) {
        ans.push_back(root->data);
        left(root->right);
    }
}
void leaves(Node* root) {
    if (root==NULL) return;
    if (root->left==NULL && root->right==NULL) ans.push_back(root->data);
    leaves(root->left);
    leaves(root->right);
}
void right(Node* root) {
    if (root == NULL) return;
    if (root->right) {
        right(root->right);
        ans.push_back(root->data);
    }
    else if (root->left) {
        right(root->left);
        ans.push_back(root->data);
    }
}
vector<int> boundaryTraversal(Node* root) {
    ans.push_back(root->data);
    left(root->left);
    leaves(root->left);
    leaves(root->right);
    right(root->right);
    return ans;
}