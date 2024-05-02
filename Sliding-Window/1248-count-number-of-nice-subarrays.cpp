// Time:  O(n)
// Space: O(n)
class Solution {
public:
  int numberOfSubarrays(vector<int>& A, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int odds = 0;
    for (int& a : A) {
      odds += a % 2 == 1 ? 1 : 0;
      if (mp.find(odds-k) != mp.end()) ans += mp[odds-k];
      mp[odds]++;
    }
    return ans;
  }
};

// Time:  O(4n)
// Space: O(1)
class Solution {
public:
  int atMost(vector<int>& A, int k) {
    int n = A.size();
    int ans = 0;
    int odds = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      odds += A[j] % 2 == 1;
      while (odds > k) {
        odds -= A[i] % 2 == 1;
        ++i;
      }
      ans += j-i+1;
    }
    return ans;
  }

  int numberOfSubarrays(vector<int>& A, int k) {
    // A continuous subarray is called nice if there are k odd numbers on it.
    return atMost(A, k) - atMost(A, k-1);
  }
};