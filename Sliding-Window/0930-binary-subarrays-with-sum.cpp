// Time:  O(n)
// Space: O(n)
class Solution {
public:
  int numSubarraysWithSum(vector<int>& A, int goal) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int x = 0;
    for (int& a : A) {
      x += a;
      if (mp.find(x-goal) != mp.end()) ans += mp[x-goal];
      mp[x]++;
    }
    return ans;
  }
};

// Time:  O(4n)
// Space: O(1)
class Solution {
public:
  int atMost(vector<int>& A, int k) {
    if (k < 0) return 0;
    int ans = 0;
    int x = 0;
    for (int i = 0, j = 0; j < A.size(); ++j) {
      x += A[j];
      while (x > k) {
        x -= A[i];
        ++i;
      }
      ans += j-i+1;
    }
    return ans;
  }
  int numSubarraysWithSum(vector<int>& A, int goal) {
    return atMost(A, goal) - atMost(A, goal-1);
  }
};