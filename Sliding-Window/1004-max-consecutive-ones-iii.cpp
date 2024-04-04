// Time  : O(2n)
// Space : O(1)

class Solution {
public:
  int longestOnes(vector<int>& A, int k) {
    int n = A.size();
    int ma = 0;
    int zeroes = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      if (A[j] == 0) zeroes++;
      while (zeroes > k) {
        zeroes -= A[i] == 0 ? 1 : 0;
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int longestOnes(vector<int>& A, int k) {
    int n = A.size();
    int ma = 0;
    int zeroes = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      if (A[j] == 0) zeroes++;
      if (zeroes > k) {
        zeroes -= A[i] == 0 ? 1 : 0;
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};