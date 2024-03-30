// Time  : O(n)
// Space : O(n)

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (s.size()) s += " ";
      if (node == NULL) {
        s += "N";
        continue;
      }
      s += to_string(node->val);
      q.push(node->left);
      q.push(node->right);
    }
    // cout<<s;
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string s) {
    if (s[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(s);
    for (string x; iss >> x; ) ip.push_back(x);
    TreeNode* root = new TreeNode(stoi(ip[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < ip.size()) {
      TreeNode* node = q.front();
      q.pop();
      if (ip[i] != "N") {
        node->left = new TreeNode(stoi(ip[i]));
        q.push(node->left);
      }
      if (++i == ip.size()) break;
      if (ip[i] != "N") {
        node->right = new TreeNode(stoi(ip[i]));
        q.push(node->right);
      }
      ++i;
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));