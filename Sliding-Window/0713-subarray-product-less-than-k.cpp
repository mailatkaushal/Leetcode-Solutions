// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& A, int k) {
    //  return the # of subarrs where product of all elements in subarr is less than k
    if (k <= 1)
      return 0;
    int n = A.size();
    int cnt = 0;
    int prod = 1;
    for (int l = 0, r = 0; r < n; ++r) {
      prod *= A[r];
      while (prod >= k) {
        prod /= A[l];
        ++l;
      }
      cnt += r-l+1;
    }
    return cnt;
  }
};

    '''
      keep a max-product-window less than k
      product num on the r, divide product on the l until subarr product is less than k again (subarr can empty)
      each iteration introduces r - l + 1 new subarrays
      window : [5,2,6] -> add 3 subarrs
                   [6]
                 [2,6]
               [5,2,6]
    '''