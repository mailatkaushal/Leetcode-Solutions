// Time  : O(n)
// Space : O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans++;
            int k=q.size();
            while (k--) {
                auto x=q.front();
                q.pop();
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
        }
        return ans;
    }
};