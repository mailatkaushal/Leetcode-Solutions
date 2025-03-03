void findPreSuc(Node* root, Node*& pre, Node*& suc, int x) {
    Node* cur=root;
    while (cur) {
        if (cur->key<x) {
            pre=cur;
            cur=cur->right;
        }
        else cur=cur->left;
    }
    cur=root;
    while (cur) {
        if (cur->key<=x) cur=cur->right;
        else {
            suc=cur;
            cur=cur->left;
        }
    }
}