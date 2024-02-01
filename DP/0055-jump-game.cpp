// Time  : O(k^n)
// Space : O(n)

class Solution {
public:
  bool canJump(vector<int>& A) {
    int n = A.size();
    vector<int> memo(n, -1);
    return f(A, n, 0, memo);
  }

  bool f(vector<int>& A, int& n, int i, vector<int>& memo) {
    if (i == n-1)
      return true;
    if (memo[i] != -1)
      return memo[i];
    
    for (int j = 1; j <= A[i]; ++j) 
      if (f(A, n, i + j, memo))
        return memo[i] = true;

    return memo[i] = false;
  }
};

// Time  : O(n^2)
// Space : O(n)

class Solution {
public:
  bool canJump(vector<int>& A) {
    int n = A.size();
    vector<bool> dp(n, false);  // dp[i] -> can reach at i
    dp[0] = true; 

    for (int i = 1; i < n; ++i) {
      for (int j = i-1; j >= 0; --j) {
        if (j + A[j] >= i && dp[j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n-1];
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  bool canJump(vector<int>& A) {
    int n = A.size();
    int maxReach = 0;

    for (int i = 0; i < n; ++i) {
      if (i > maxReach)
        return false;
      maxReach = max(maxReach, i + A[i]);
    }

    return true;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  bool canJump(vector<int>& A) {
    int n = A.size();
    int goal = n-1;

    for (int i = n-2; i >= 0; --i) {
      if (i + A[i] >= goal)
        goal = i;
    }

    return goal == 0;
  }
};