// Time  : O(n)
// Space : O(n)
int widthOfBinaryTree(TreeNode* root) {
    int ans=0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while (!q.empty()) {
        int k=q.size();
        int x=q.front().second;
        int y=q.back().second;
        ans=max(ans,y-x+1);
        while (k--) {
            auto p=q.front();
            q.pop();
            int idx=p.second-x;
            if (p.first->left) q.push({p.first->left,2*idx+1});
            if (p.first->right) q.push({p.first->right,2*idx+2});
        }
    }
    return ans;
}