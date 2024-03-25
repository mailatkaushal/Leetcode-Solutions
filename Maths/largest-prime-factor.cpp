// Time  : O(sqrt(n)*2sqrt(n))
// Space : O(1)

class Solution{
public: 
  bool isPrime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i*i <= n; ++i) 
      if (n % i == 0) 
        return 0;
    return 1;
  }

  int largestPrimeFactor(int n){
    // n : 2 -> 1e9
    int ma = 2;
    for (int i = 1; i*i <= n; ++i) {
      if (n % i == 0) {
        if (isPrime(i))
          ma = max(ma, i);
        int j = n / i;
        if (isPrime(j)) 
          ma = max(ma, j);
      }
    }
    return ma;
  }
};

// Time  : O(sqrt(n)*logn)
// Space : O(1)

class Solution{
public: 
  int largestPrimeFactor(int n){
    int ma = 2;
    for (int i = 2; i*i <= n; ++i) {
      if (n % i == 0) {
        ma = i;
        while (n % i == 0)
          n = n / i;
      }
    }
    if (n == 1) 
      return ma;
    return n;
  }
};