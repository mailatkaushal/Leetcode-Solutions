// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
  static bool compare(vector<int>& a, vector<int>& b) {
    return a[0] <= b[0];
  }

  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> A(n, vector<int> (3));

    for (int i = 0; i < n; ++i) {
      A[i][0] = startTime[i]; 
      A[i][1] = endTime[i]; 
      A[i][2] = profit[i]; 
    }

    sort(A.begin(), A.end(), compare);

    vector<int> dp(n);
    dp[n-1] = A[n-1][2];

    for (int i = n-2; i >= 0; --i) {
      int next = lowerBound(i, A);
      dp[i] = max(
        A[i][2] + (next == -1 ? 0 : dp[next]),
        dp[i+1]
      );
    }

    return dp[0];
  }

  int lowerBound(int& i, vector<vector<int>>& A) {
    int l = i+1, r = A.size()-1;
    int res = -1;

    while (l <= r) {
      int mid = l + (r-l)/2;
      if (A[mid][0] >= A[i][1]) {
        res = mid;
        r = mid-1;
      }
      else 
        l = mid+1;
    }

    return res;
  }
};