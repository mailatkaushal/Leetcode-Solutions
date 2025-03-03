// Time  : O(logɸ(min(a,b)))
// Space : O(1)
int calcGCD(int a, int b) {
  while (b) {
    int rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}