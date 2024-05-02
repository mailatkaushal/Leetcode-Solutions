// Time:  O(n)
// Space: O(n)
class Solution {
public:
  int subarraySum(vector<int>& A, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int x = 0;
    for (int& a : A) {
      x += a;
      if (mp.find(x-k) != mp.end()) ans += mp[x-k];
      mp[x]++;
    }
    return ans;
  }
};