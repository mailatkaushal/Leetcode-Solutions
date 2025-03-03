// Time  : O(n)
// Space : O(h)
Node* prev;
void f(Node* root) {
    if (root==NULL) return;
    f(root->left);
    prev->right=root;
    root->left=prev;
    prev=root;
    f(root->right);
}
Node* bToDLL(Node* root) {
    Node* dummy=new Node(0);
    prev=dummy;
    f(root);
    auto head=dummy->right;
    head->left=NULL;
    return head;
}