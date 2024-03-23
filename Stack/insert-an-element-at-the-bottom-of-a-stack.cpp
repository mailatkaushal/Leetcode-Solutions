// Time  : O(2n)
// Space : O(n)

class Solution{
public:
  stack<int> insertAtBottom(stack<int> stk, int val){
    int n = stk.size();
    vector<int> v(n);
    int x = 0;
    for (int i = 0; i < n; ++i) {
      v[x++] = stk.top();
      stk.pop();
    }
    stk.push(val);
    for (int i = n-1; i >= 0; --i) {
      stk.push(v[i]);
    }
    return stk;
  }
};