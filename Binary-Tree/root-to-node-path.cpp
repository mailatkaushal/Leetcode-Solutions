bool f(TreeNode<int>* root, int x, vector<int>& path) {
	if (root == NULL)
		return false;
	path.push_back(root->data);
	if (root->data == x)
		return true;
	if (f(root->left, x, path) || f(root->right, x, path))
		return true;
	path.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int>* root, int x) {
	vector<int> path;
    f(root, x, path);
	return path;
}