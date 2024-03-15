// Time  : O(nlogm) - Where n is size of A, m is the max in A
// Space : O(1)

class Solution {
public:
  int smallestDivisor(vector<int>& A, int threshold) {
    // return the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division’s result is less than or equal to the given threshold value.

    if (n > threshold)
      return -1;

    int lo = 1, hi = *max_element(A.begin(), A.end());

    while (lo < hi) {
      int div = lo + (hi - lo) / 2;
      int sum = 0;
      for (int& n : A)
        sum += ceil((double)n / div);
      if (sum > threshold)
        lo = div + 1;
      else
        hi = div;
    }

    return lo;
  }
};