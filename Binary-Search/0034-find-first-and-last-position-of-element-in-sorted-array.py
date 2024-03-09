# custom binary search
# Time  : O(logn)
# Sapce : O(1)

class Solution:
  def searchRange(self, A: List[int], target: int) -> List[int]:
    n = len(A)
    res = [0] * 2

    i = -1
    lo, hi = 0, n - 1
    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      elif A[mid] > target:
        hi = mid - 1
      else:
        i = mid
        hi = mid - 1
    res[0] = i

    i = -1
    lo, hi = 0, n - 1
    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      elif A[mid] > target:
        hi = mid - 1
      else:
        i = mid
        lo = mid + 1
    res[1] = i

    return res
  
# c++ stl
# Time  : O(logn)
# Sapce : O(1)
 
class Solution {
public:
  vector<int> searchRange(vector<int>& A, int target) {
    // index of first element equal to or greater than target
    int l = lower_bound(A.begin(), A.end(), target) - A.begin();

    // index of first element greater than target
    int r = upper_bound(A.begin(), A.end(), target) - A.begin();

    if (l < A.size() && A[l] == target)
      return {l, r-1};

    return {-1, -1};
  }
};

# lower_bound and upper_bound in python 

class Solution:
  def searchRange(self, A: List[int], target: int) -> List[int]:
    n = len(A)

    def lowerBound():
      lo, hi = 0, n
      while lo < hi:
        mid = lo + (hi - lo) // 2
        if A[mid] < target:
          lo = mid + 1
        else:
          hi = mid
      return lo

    def upperBound():
      lo, hi = 0, n
      while lo < hi:
        mid = lo + (hi - lo) // 2
        if A[mid] <= target:
          lo = mid + 1
        else:
          hi = mid
      return lo
      
    l = lowerBound()
    r = upperBound()

    if l < n and A[l] == target:
      return [l, r - 1]
    
    return [-1, -1]