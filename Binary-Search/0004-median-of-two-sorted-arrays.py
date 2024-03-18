#  Time  : O(m + n)
#  Space : O(m + n)

class Solution {
public:
  double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size();
    vector<int> C(m + n);
    int x = 0;
    int i = 0, j = 0;

    while (i < m && j < n) {
      if (A[i] <= B[j])
        C[x++] = A[i++];
      else
        C[x++] = B[j++];
    }

    while (i < m)
      C[x++] = A[i++];
    while (j < n)
      C[x++] = B[j++];

    int len = C.size();
    if (len % 2 == 1)
      return C[len / 2];
    return (C[len / 2 - 1] + C[len / 2]) / 2.0;
  }
};

#  Time  : O((n1 + n2) / 2)
#  Space : O(1)

class Solution:
  def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
    n1, n2 = len(A), len(B)
    n = n1 + n2
    mid1, mid2 = n // 2 - 1, n // 2
    mid1el, mid2el = -1, -1
    x = 0
    i, j = 0, 0

    while i < n1 and j < n2:
      if mid1el != -1 and mid2el != -1:
        break
      if A[i] < B[j]:
        if x == mid1:
          mid1el = A[i]
        if x == mid2:
          mid2el = A[i]
        i += 1
      else:
        if x == mid1:
          mid1el = B[j]
        if x == mid2:
          mid2el = B[j]
        j += 1
      x += 1

    while i < n1:
      if mid1el != -1 and mid2el != -1:
        break
      if x == mid1:
        mid1el = A[i]
      if x == mid2:
        mid2el = A[i]
      i += 1
      x += 1

    while j < n2:
      if mid1el != -1 and mid2el != -1:
        break
      if x == mid1:
        mid1el = B[j]
      if x == mid2:
        mid2el = B[j]
      j += 1
      x += 1

    if n % 2 == 1:
      return mid2el
    
    return (mid1el + mid2el) / 2

#  Time  : O(log(min(n1 + n2)))
#  Space : O(1)

class Solution:
  def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
    # Apply binary search to the smaller arr
    if len(A) > len(B):
      return self.findMedianSortedArrays(B, A)

    n1, n2 = len(A), len(B)
    n = n1 + n2
    lo, hi = 0, n1

    while lo <= hi:
      mid1 = lo + (hi - lo) // 2
      mid2 = (n + 1) // 2 - mid1

      l1 = A[mid1 - 1] if mid1 > 0 else float('-inf')
      l2 = B[mid2 - 1] if mid2 > 0 else float('-inf')
      r1 = A[mid1] if mid1 < n1 else float('inf')
      r2 = B[mid2] if mid2 < n2 else float('inf')

      if l1 <= r2 and l2 <= r1:
        if n % 2 == 1:
          return max(l1, l2)
        return (max(l1, l2) + min(r1, r2)) / 2
      elif l1 > r2:
        hi = mid1 - 1
      else:
        lo = mid1 + 1