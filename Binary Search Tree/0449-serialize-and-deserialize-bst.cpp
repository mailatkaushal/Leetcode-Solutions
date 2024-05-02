// Time  : O(n)
// Space : O(n)
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == NULL) return "";
    string data;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* x = q.front();
      q.pop();
      if (x == NULL) {
        data += "N ";
        continue;
      }
      data += to_string(x->val) + ' ';
      q.push(x->left);
      q.push(x->right);
    }
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "") return NULL;
    stringstream ss(data);
    string d;
    getline(ss, d, ' ');
    TreeNode* root = new TreeNode(stoi(d));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* x = q.front();
      q.pop();
      getline(ss, d, ' ');
      if (d != "N") {
        x->left = new TreeNode(stoi(d));
        q.push(x->left);
      }
      getline(ss, d, ' ');
      if (d != "N") {
        x->right = new TreeNode(stoi(d));
        q.push(x->right);
      }
    }
    return root;
  }
};