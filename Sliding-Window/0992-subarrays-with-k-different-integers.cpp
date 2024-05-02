// Time  : O(n)
// Space : O(n)
class Solution {
public:
  int atMost(vector<int>& A, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0, j = 0; j < A.size(); ++j) {
      mp[A[j]]++;
      while (mp.size() > k) {
        mp[A[i]]--;
        if (mp[A[i]] == 0) mp.erase(A[i]);
        ++i;
      }
      ans += j-i+1;
    }
    return ans;
  }
  int subarraysWithKDistinct(vector<int>& A, int k) {
    return atMost(A, k) - atMost(A, k-1);
  }
};