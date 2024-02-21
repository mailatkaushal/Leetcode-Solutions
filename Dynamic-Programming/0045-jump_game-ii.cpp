/*
  1-dimensional BFS
  Time  : O(n)
  Space : O(1)
*/

class Solution {
public:
  int jump(vector<int>& A) {
    int res = 0;
    int l = 0, r = 0;

    while (r < A.size()-1) {
      int farthest = 0;
      for (int i = l; i <= r; ++i)
        farthest = max(farthest, i + A[i]);
      l = r + 1;
      r = farthest;
      ++res;
    }

    return res;
  }
};