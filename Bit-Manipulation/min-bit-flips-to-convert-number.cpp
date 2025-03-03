// Time  : O(32)
// Space : O(1)
int minBitFlips(int start, int goal) {
  int diff=0;
  int x=start^goal;
  while (x) {
      diff+=(x&1);
      x>>=1;
  }
  return diff;
}
int minBitFlips(int start, int goal) {
  int diff=0;
  int x=start^goal;
  while (x) {
      x=x&(x-1);
      ++diff;
  }
  return diff;
}