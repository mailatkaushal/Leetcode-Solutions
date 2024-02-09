// Time  : O(2^n)
// Space : O(n)

class Solution {
public:
  int fib(int n) {
    if (n <= 1)
      return n;

    return fib(n-1) + fib(n-2);
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int fib(int& n) {
    vector<int> memo(n+1, -1);
    return f(n, memo);
  }

  int f(int n, vector<int>& memo) {
    if (n <= 1)
      return n;
    if (memo[n] != -1)
      return memo[n];

    return memo[n] = f(n-1, memo) + f(n-2, memo);
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int fib(int& n) {
    if (n == 0)
      return n;

    vector<int> v(n+1);
    v[1] = 1;

    for (int i = 2; i <= n; ++i) 
      v[i] = v[i-1] + v[i-2];

    return v[n];
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int fib(int& n) {
    if (n == 0)
      return n;

    int a = 0;
    int b = 1;
    int c;
    
    for (int i = 2; i <= n; ++i) {
      c = a + b;
      a = b;
      b = c;
    }

    return c;
  }
};