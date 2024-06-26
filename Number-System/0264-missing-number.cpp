// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int missingNumber(vector<int>& A) {
    int ret = 0;
    for (int i=0; i<A.size(); ++i) ret ^= (i+1) ^ A[i];
    return ret;
  }
};