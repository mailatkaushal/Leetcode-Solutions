// Time  : O(min(a, b))
// Space : O(1)

int calcGCD(int a, int b) {
  for (int i = min(a, b); i >= 1; --i) {
    if (a % i == 0 && b % i == 0)
      return i;
  }
}

// Time  : O(logɸ(min(a,b)))
// Space : O(1)
// Euclid Algorith
// gcd(a, b) = gcd(b, a % b)

int calcGCD(int a, int b) {
  while (b) {
    int rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}