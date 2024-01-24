// Time: O(30*logn)
// Space: O(logn)

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<int> countN = count(n);
    for (int i = 0; i < 30; ++i) {
      if (countN == count(1<<i)) 
        return true;
    }
    return false;
  }

  vector<int> count(int n) {
    vector<int> v(10, 0);
    while (n) {
      ++v[n % 10];
      n /= 10;
    }
    return v;
  }
};
