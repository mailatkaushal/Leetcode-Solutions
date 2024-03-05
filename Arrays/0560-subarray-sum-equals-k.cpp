// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
  int subarraySum(vector<int>& A, int k) {
    int n = A.size();
    int cnt = 0;
    vector<int> dp(n+1);

    for (int i = 1; i <= n; ++i) 
      dp[i] = dp[i-1] + A[i-1];

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (k == dp[i] - dp[j])
          ++cnt;
      }
    }

    return cnt;
  }
};

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> ump;
    ump[0] = 1;
    int sum = 0;
    
    for (int& num : nums) {
      sum += num;
      if (ump.find(sum - k) != ump.end()) 
        res += ump[sum - k];
      ump[sum]++;
    }

    return res;
  }
};