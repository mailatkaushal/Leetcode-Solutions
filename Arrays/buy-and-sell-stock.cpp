// Time:  O(n)
// Space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    int minn = prices[0];
    for (int i=1; i<n; ++i) {
      ans = max(ans, prices[i] - minn);
      minn = min(minn, prices[i]);
    }
    return ans;
  }
};