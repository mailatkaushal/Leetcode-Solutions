// Time:  O(n^3)
// SPace: O(1)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int n = A.size();

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int mini = INT_MAX;
        for (int k = 0; k < n; ++k) {
          if (k != j && A[i-1][k] < mini) 
            mini = A[i-1][k];
        }
        A[i][j] += mini;
      }
    }

    return *min_element(A[n-1].begin(), A[n-1].end());
  }
};