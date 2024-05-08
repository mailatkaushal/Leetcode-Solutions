// Time  : O(logn)
// Space : O(1)
class Solution{
public:
	int floor(Node* root, int x) {
		int ans = -1;
		while (root) {
			if (root->data == x) return x;
			if (root->data < x) {
				ans = root->data;
				root = root->right; 
			}
			else root = root->left;
		}
		return ans;
	}
};