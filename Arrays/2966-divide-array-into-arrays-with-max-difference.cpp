// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& A, int k) {
    int n = A.size();
    vector<vector<int>> res;
    
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i += 3) {
      if (A[i+2] - A[i] <= k) 
        res.push_back({A[i], A[i+1], A[i+2]});
      else 
        return {};
    }

    return res;
  }
};