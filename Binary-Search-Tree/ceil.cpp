int findCeil(Node* root, int x) {
    int ans=-1;
    while (root) {
        if (root->data==x) return x;
        if (x<root->data) {
            ans=root->data;
            root=root->left;
        }
        else root=root->right;
    }
    return ans;
}