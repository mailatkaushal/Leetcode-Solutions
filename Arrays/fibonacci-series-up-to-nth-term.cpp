// Time  : O(n)
// Space : O(n)

class Solution {
  public:
  vector<int> Series(int n) {
    int MOD = 1e9+7;
    vector<int> res(n+1);
    res[1] = 1;

    for (int i = 2; i <= n; ++i) 
      res[i] = (res[i-2]  + res[i-1]) % MOD;
    
    return res;
  }
};