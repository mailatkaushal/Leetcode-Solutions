// Time  : O(m+n)
// Space : O(m+n)

class Solution {
public:
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> a;
        while (root1) {
            if (root1->left == NULL) {
                a.push_back(root1->data);
                root1 = root1->right;
            }
            else {
                Node* pre = root1->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = root1;
                Node* tmp = root1;
                root1 = root1->left;
                tmp->left = NULL;
            }
        }
        vector<int> b;
        while (root2) {
            if (root2->left == NULL) {
                b.push_back(root2->data);
                root2 = root2->right;
            }
            else {
                Node* pre = root2->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = root2;
                Node* tmp = root2;
                root2 = root2->left;
                tmp->left = NULL;
            }
        }
        int i = 0;
        int j = 0;
        int m = a.size();
        int n = b.size();
        vector<int> c(m+n);
        int k = 0;
        while (i < m && j < n) {
            if (a[i] <= b[j])
                c[k++] = a[i++];
            else 
                c[k++] = b[j++];
        }
        while (i < m) c[k++] = a[i++];
        while (j < n) c[k++] = b[j++];
        return c;
    }
};