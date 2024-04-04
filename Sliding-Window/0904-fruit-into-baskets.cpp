// Time  : O(2n)
// Space : O(3) ~ O(1)

class Solution {
public:
  int totalFruit(vector<int>& A) {
    int n = A.size();
    int ma = 0;
    unordered_map<int, int> ump;
    for (int i = 0, j = 0; j < n; ++j) {
      ++ump[A[j]];
      while (ump.size() > 2) {
        --ump[A[i]];
        if (ump[A[i]] == 0) ump.erase(A[i]);
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};

// Time  : O(n)
// Space : O(3) ~ O(1)

class Solution {
public:
  int totalFruit(vector<int>& A) {
    int n = A.size();
    int ma = 0;
    unordered_map<int, int> ump;
    for (int i = 0, j = 0; j < n; ++j) {
      ++ump[A[j]];
      if (ump.size() > 2) {
        --ump[A[i]];
        if (ump[A[i]] == 0) ump.erase(A[i]);
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};