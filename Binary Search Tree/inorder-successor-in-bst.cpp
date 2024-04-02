// Time  : O(n)
// Time  : O(n)

class Solution{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node* root, Node* x) {
        vector<Node*> inorder;
        while (root) {
            if (root->left == NULL) {
                inorder.push_back(root);
                root = root->right;
            }
            else {
                Node* prev = root->left;
                while (prev->right) 
                    prev = prev->right;
                prev->right = root;
                Node* tmp = root;
                root = root->left;
                tmp->left = NULL;
            }
        }
        for (int i = 0; i < inorder.size() - 1; ++i) 
            if (inorder[i] == x) 
                return inorder[i+1];
        return NULL;
    }
};

// Time  : O(n)
// Time  : O(1)

class Solution{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node* root, Node* x) {
        while (root) {
            if (root->left == NULL) {
                if (root->data > x->data) return root;
                root = root->right;
            }
            else {
                Node* prev = root->left;
                while (prev->right) 
                    prev = prev->right;
                prev->right = root;
                Node* tmp = root;
                root = root->left;
                tmp->left = NULL;
            }
        }
        return NULL;
    }
};

// Time  : O(logn)
// Time  : O(1)

class Solution{
 public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node* root, Node* x) {
        Node* y = NULL;
        while (root) {
            if (root->data <= x->data) 
                root = root->right;
            else {
                y = root;
                root = root->left;
            }
        }
        return y;
    }
};