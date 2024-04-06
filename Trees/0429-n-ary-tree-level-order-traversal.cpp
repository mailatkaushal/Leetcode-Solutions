// Time  : O(n)
// Space : O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (root == NULL) return {};
    vector<vector<int>> vv;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> v;
      int n = q.size();
      while (n--) {
        Node* node = q.front();
        q.pop();
        v.push_back(node->val);
        int x = node->children.size();
        for (int i = 0; i < x; ++i) 
          if (node->children[i]) q.push(node->children[i]);
      }
      vv.push_back(v);
    }
    return vv;
  }
};