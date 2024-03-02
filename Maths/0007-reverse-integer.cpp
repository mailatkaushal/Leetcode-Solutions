// Time  : O(logx)
// Space : O(1)

class Solution {
public:
  int reverse(int x) {
    long long num = abs(x);  // -2147483648
    long long rev = 0;

    while (num) {
      int digit = num % 10;
      rev = rev * 10 + digit;
      num /= 10;
    }

    if (rev > INT_MAX || rev < INT_MIN)
      return 0;

    return x >= 0 ? (int)rev : -1 * (int)rev;
  }
};

// Time  : O(logx)
// Space : O(1)

class Solution {
public:
  int reverse(int x) {
    int rev = 0;

    while (x) {
      int digit = x % 10;

      /*
        INT_MAX = 2147483647
        INT_MAX / 10 = 214748364
        So, if rev > 214748364, say 214748365
        then definitely rev * 10 (2147483650) is overflowing
        
        Also, if rev = INT_MAX / 10 = 214748364
        Then rev * 10 = 2147483640
        But then digit must be <= 7 to avoid overflow
      */
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
        return 0;

      /*
        INT_MIN = -2147483648
        INT_MIN / 10 = -214748364
        So, if rev < -214748364, say -214748365
        then definitely rev * 10 (-2147483650) is overflowing
        
        Also, if rev = INT_MIN / 10 = -214748364
        Then  rev * 10 = -2147483640
        But then digit must be >= -8 to avoid overflow
      */
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
        return 0;

      rev = rev * 10 + digit;
      x /= 10;
    }

    return rev;
  }
};

// Time  : O(logx)
// Space : O(1)

class Solution {
public:
  int reverse(int x) {
    // rev == INT_MAX / 10 && digit > 7 
    // rev == INT_MIN / 10 && digit < -8
    // based on the input: -2^31 to 2^31 - 1, we can never have the first digit to be greater than 2 or lessed than 1
    // So when we reverse this number, the units place can never have any number greater than 2 or lesses than 1. This condition gets set by default due to the constraints on input
    // So even if we remove this piece from the code, it should run fine

    int rev = 0;

    while (x != 0) {
      if (rev < INT_MIN / 10 || rev > INT_MAX / 10) 
        return 0;
      
      int digit = x % 10;
      rev = rev * 10 + digit;
      x /= 10;
    }

    return rev;
  }
};