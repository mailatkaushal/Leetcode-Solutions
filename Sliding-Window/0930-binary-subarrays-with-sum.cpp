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

// Time:  O(4n)
// Space: O(1)

class Solution {
public:
  int atMost(vector<int>& A, int k) {
    if (k < 0) return 0;
    int n = A.size();
    int cnt = 0;
    int sum = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      sum += A[j];
      while (sum > k) {
        sum -= A[i];
        ++i;
      }
      cnt += j-i+1;
    }
    return cnt;
  }

  int numSubarraysWithSum(vector<int>& A, int k) {
    return atMost(A, k) - atMost(A, k-1);
  }
};