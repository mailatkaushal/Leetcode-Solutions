vector<string> v;
void f(BinaryTreeNode<int>* root, string tmp) {
  if (root == NULL)
    return;
  if (tmp.size())
    tmp += " ";
  tmp += to_string(root->data);
  if (root->left == NULL && root->right == NULL) {
    v.push_back(tmp);
    return;
  }
  f(root->left, tmp);
  f(root->right, tmp);
}
vector<string> allRootToLeaf(BinaryTreeNode<int>* root) {
  f(root, "");
  return v;
}