// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> stk;

    for (int i = n-1; i >= 0; --i) {
      while (!stk.empty() && A[i] >= A[stk.top()])
        stk.pop();

      if (!stk.empty())
        res[i] = stk.top() - i;
      // else 
      //   res[i] = 0;

      stk.push(i);
    }

    return res;
  }
};