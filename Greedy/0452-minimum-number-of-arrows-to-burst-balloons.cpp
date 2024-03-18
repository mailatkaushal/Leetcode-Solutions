// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& A) {
    sort(A.begin(), A.end(), [&] (auto& a, auto& b) {
      return a[1] < b[1];
    });

    int end = A[0][1];
    int arrows = 1;

    for (int i = 1; i < A.size(); ++i) {
      if (end >= A[i][0]) 
        continue;
      ++arrows;
      end = A[i][1];
    }

    return arrows;
  }
};