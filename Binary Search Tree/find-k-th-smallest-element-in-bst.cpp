// Time  : O(n)
// Space : O(1)
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node* x, int k) {
        int i = 0;
        int kthsmall = -1;
        while (x) {
            if (x->left == NULL) {
                if (++i == k) {
                    kthsmall = x->data;
                    break;
                }
                x = x->right;
            }
            else {
                Node* pre = x->left;
                while (pre->right) pre = pre->right;
                pre->right = x;
                Node* tmp = x;
                x = x->left;
                tmp->left = NULL;
            }
        }
        return kthsmall;
    }
};