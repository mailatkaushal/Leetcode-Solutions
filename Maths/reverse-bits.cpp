// Time  : O(32)
// Space : O(1)

long reverseBits(long n) {
  long rev = 0;
  for (int i = 0; i < 32; ++i) {
    int bit = n % 2;
    rev = rev * 2 + bit;
    n /= 2;
  }
  return rev;
}