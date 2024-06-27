class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    for (int i=0; i<n-2; ++i) {
      if (i > 0 && A[i-1] == A[i]) continue;
      int j = i+1;
      int k = n-1;
      while (j < k) {
        int sum = A[i]+A[j]+A[k];
        if (sum == 0) { 
          ans.push_back({A[i],A[j++],A[k--]});
          while (j < k && A[j-1] == A[j]) ++j;
          while (j < k && A[k] == A[k+1]) --k;
        }
        else if (sum < 0) ++j;
        else --k;
      }
    }
    return ans;
  }
};