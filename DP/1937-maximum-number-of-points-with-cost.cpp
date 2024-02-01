// Bruteforce - TLE
// Time:  O(m*n^2)
// Space: O(n)

class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<long long> prev(m);
    for (int i = 0; i < n; ++i)
      prev[i] = points[0][i];

    for (int i = 1; i < m; ++i) {
      vector<long long> curr(n);
      for (int j = 0; j < n; ++j) {
        long long maxi = INT_MIN;
        for (int k = 0; k < n; ++k) 
          maxi = max(maxi, points[i][j] + prev[k] + (j-k));
        curr[j] = maxi;
      }
      prev = curr;
    }

    return *max_element(prev.begin(), prev.end());
  }
};

// Time:  O(m*n)
// Space: O(n)

typedef long long ll;
class Solution {
public:
  long long maxPoints(vector<vector<int>>& P) {
    int m = P.size();
    int n = P[0].size();

    vector<ll> prev(n);

    for (int i = 0; i < n; ++i)
      prev[i] = P[0][i];
    
    for (int i = 1; i < m; ++i) {
      vector<ll> lft(n), rgt(n), curr(n);
      lft[0] = prev[0];
      rgt[n-1] = prev[n-1];

      for (int j = 1; j < n; ++j)
        lft[j] = max(lft[j-1] - 1, prev[j]);

      for (int j = n-2; j >= 0; --j)
        rgt[j] = max(rgt[j+1] - 1, prev[j]);

      for (int j = 0; j < n; ++j) 
        curr[j] = P[i][j] + max(lft[j], rgt[j]);

      prev = curr;
    }
    
    ll res = 0;

    for (ll& r: prev) 
      res = max(res, r);

    return res;
  }
};