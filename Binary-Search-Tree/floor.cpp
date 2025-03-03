int floor(Node* root, int x) {
	int ans=-1;
	while (root) {
		if (root->data==x) return x;
		if (x<root->data) root=root->left;
		else {
			ans=root->data;
			root=root->right;
		}
	}
	return ans;
}