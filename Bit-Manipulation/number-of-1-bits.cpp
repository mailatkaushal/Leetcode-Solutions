// Time  : O(no. of set bits in n)
// Space : O(1)
int hammingWeight(int n) {
  int ans=0;
  while (n) {
      n=n&(n-1);
      ++ans;
  }
  return ans;
}