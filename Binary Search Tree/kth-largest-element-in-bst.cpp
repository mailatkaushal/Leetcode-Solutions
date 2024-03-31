// Time  : O(n)
// Space : O(1)

class Solution {
  public:
    int kthLargest(Node* root, int k) {
        int cnt = 0;
        int kthlar;
        Node* cur = root;
        while (cur) {
            if (cur->right == NULL) {
                ++cnt;
                if (cnt == k) {
                    kthlar = cur->data;
                    break;
                }
                cur = cur->left;
            }
            else {
                Node* prev = cur->right;
                while (prev->left)
                    prev = prev->left;
                prev->left = cur;
                Node* tmp = cur;
                cur = cur->right;
                tmp->right = NULL;
            }
        }
        return kthlar;
    }
};