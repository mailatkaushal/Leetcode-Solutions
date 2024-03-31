// Time  : O(logn)
// Space : O(1)

class Solution{
public:
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
        int f = -1;
        while (root) {
            if (root->data == x)
                return x;
            else if (root->data < x) {
                f = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return f;
    }
};