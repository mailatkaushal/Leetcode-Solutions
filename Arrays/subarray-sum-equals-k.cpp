// Time:  O(n)
// Space: O(n)
class Solution {
public:
  int subarraySum(vector<int>& A, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i=0; i<A.size(); ++i) {
      sum += A[i];
      ans += mp[sum-k];
      mp[sum]++;
    }
    return ans;
  }
};