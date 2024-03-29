# Time  : O(logn)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> int:
    lo, hi = 0, len(A) - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      elif A[mid] > target:
        hi = mid - 1
      else:
        return mid

    return -1

# Time  : O(logn)
# Space : O(logn)

class Solution {
public:
  int binarySearch(vector<int>& A, int target, int lo, int hi) {
    if (lo > hi)
      return -1;
    int mid = lo + (hi - lo) / 2;
    if (A[mid] < target)
      return binarySearch(A, target, mid+1, hi);
    else if (A[mid] > target)
      return binarySearch(A, target, lo, mid-1);
    else
      return mid;
  }
  int search(vector<int>& A, int target) {
    int n = A.size();
    return binarySearch(A, target, 0, n-1);
  }
};