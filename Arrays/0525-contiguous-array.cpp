// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int findMaxLength(vector<int>& A) {
    int max_len = 0;
    unordered_map<int, int> ump;
    ump[0] = -1;
    int sum = 0;

    for (int i = 0; i < A.size(); ++i) {
      sum += A[i] == 0 ? -1 : 1;
      if (ump.find(sum) != ump.end()) 
        max_len = max(max_len, i - ump[sum]);
      else
        ump[sum] = i;
    }

    return max_len;
  }
};