class Solution:
  def numSubarrayProductLessThanK(self, A: List[int], k: int) -> int:
    # return the # of subarrs where product of all elements in subarr is less than k
    
    prod = A[0]
    cnt = 1 if prod < k else 0
    l = 0

    for r in range(1, len(A)):
      prod *= A[r]
      while l <= r and prod >= k:
        prod //= A[l]
        l += 1
      cnt += r - l + 1
    
    return cnt

    '''
      keep a max-product-window less than k
      product num on the r, divide product on the l until subarr product is less than k again (subarr can empty)
      each iteration introduces r - l + 1 new subarrays
      window : [5,2,6] -> add 3 subarrs
                   [6]
                 [2,6]
               [5,2,6]
    '''