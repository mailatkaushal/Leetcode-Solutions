// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int missingNumber(vector<int>& A) {
    int x = 0;
    for (int i = 1; i <= A.size(); ++i) x ^= i;
    for (int& a : A) x ^= a;
    return x;
  }
};