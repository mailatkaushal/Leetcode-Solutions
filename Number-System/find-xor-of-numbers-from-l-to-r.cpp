// Time  : O(1)
// Space : O(1)
class Solution {
public:
  int f1toN(int n) {
    int x = n % 4;
    if (x == 1) return 1;
    if (x == 2) return n+1;
    if (x == 3) return 0;
    return n;
  }
  int findXOR(int l, int r) {
    return f1toN(l-1) ^ f1toN(r); 
  }
};