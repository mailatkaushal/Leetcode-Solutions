// Time  : O(n)
// Space : O(h)
int ans=0;
int f(Node* root) {
    if (root==NULL) return 0;
    int lh=f(root->left);
    int rh=f(root->right);
    ans=max(ans,lh+rh);
    return max(lh,rh)+1;
}
int diameter(Node* root) {
    f(root);
    return ans;
}