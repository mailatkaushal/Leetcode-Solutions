vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	unordered_map<TreeNode*,TreeNode*> parent;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		auto x=q.front();
		q.pop();
		if (x->left) {
			parent[x->left]=x;
			q.push(x->left);
		}
		if (x->right) {
			parent[x->right]=x;
			q.push(x->right);
		}
	}
	q.push(target);
	unordered_set<TreeNode*> vis;
	vis.insert(target);
	int d=-1;
	while (!q.empty()) {
		++d;
		if (d==k) break;
		int n=q.size();
		while (n--) {
			auto x=q.front();
			q.pop();
			if (parent.find(x)!=parent.end() && vis.find(parent[x])==vis.end()) {
				vis.insert(parent[x]);
				q.push(parent[x]);
			}
			if (x->left && vis.find(x->left)==vis.end()) {
				vis.insert(x->left);
				q.push(x->left);
			}
			if (x->right && vis.find(x->right)==vis.end()) {
				vis.insert(x->right);
				q.push(x->right);
			}
		}
	}
	vector<int> ans;
	while (!q.empty()) {
		ans.push_back(q.front()->val);
		q.pop();
	}
	return ans;
}