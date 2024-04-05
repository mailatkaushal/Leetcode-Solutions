// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int numberOfSubarrays(vector<int>& A, int k) {
    int cnt = 0;
    unordered_map<int, int> ump;
    ump[0] = 1;
    int odds = 0;
    for (int& a : A) {
      odds += (a % 2);
      cnt += ump[odds - k]; 
      ++ump[odds];
    }
    return cnt;
  }
};

// Time:  O(4n)
// Space: O(1)

class Solution {
public:
  int atMost(vector<int>& A, int k) {
    int n = A.size();
    int cnt = 0;
    int odds = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      if (A[j] % 2 == 1) ++odds;
      while (odds > k) {
        if (A[i] % 2 == 1) --odds;
        ++i;
      }
      cnt += j-i+1;
    }
    return cnt;
  }

  int numberOfSubarrays(vector<int>& A, int k) {
    // A continuous subarray is called nice if there are k odd numbers on it.
    return atMost(A, k) - atMost(A, k-1);
  }
};