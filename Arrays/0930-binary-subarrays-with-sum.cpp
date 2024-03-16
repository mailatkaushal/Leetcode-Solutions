// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
  int numSubarraysWithSum(vector<int>& A, int goal) {
    int n = A.size();
    int cnt = 0;
    vector<int> dp(n+1);

    for (int i = 1; i <= n; ++i) 
      dp[i] = dp[i-1] + A[i-1];

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[i] - dp[j] == goal)
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
  int numSubarraysWithSum(vector<int>& A, int goal) {
    int cnt = 0;
    unordered_map<int, int> ump;
    ump[0] = 1;
    int sum = 0;
    
    for (int& n : A) {
      sum += n;
      if (ump.find(sum - goal) != ump.end())
        cnt += ump[sum - goal];
      ++ump[sum];
    }

    return cnt;
  }
};