// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int minSubArrayLen(int& target, vector<int>& A) {
    int n = A.size();
    int len = INT_MAX;
    int sum = 0;
    
    for (int l = 0, r = 0; r < n; ++r) {
      sum += A[r];
      while (sum >= target) {
        len = min(len, r - l + 1);
        sum -= A[l];
        l++;
      }
    }

    return len == INT_MAX ? 0 : len;
  }
};