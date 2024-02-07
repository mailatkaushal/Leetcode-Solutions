// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int totalHammingDistance(vector<int>& A) {
    int n = A.size();
    int res = 0;

    for (int k = 0; k < 32; ++k) { 
      int cnt = 0;  // number of 1 bit

      for (int i = 0; i < n; ++i) 
        cnt += (A[i] >> k) & 1;

      res += cnt * (n - cnt);  // distance on this particular bit
    }

    return res;
  }
};