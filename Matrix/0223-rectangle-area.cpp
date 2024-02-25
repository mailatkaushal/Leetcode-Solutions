// Time  : O(1)
// Space : O(1)

class Solution:
  def computeArea(self, l1: int, b1: int, r1: int, t1: int, l2: int, b2: int, r2: int, t2: int) -> int:
    # find the edges of the overlaped area
    l = max(l1, l2)
    r = min(r1, r2)
    b = max(b1, b2)
    t = min(t1, t2)

    # if both edges are positive, it means that the overlap has positive area -> substract it
    # total area covered = area of rec1 + area of rec2 - overlapped area
    if r - l > 0 and t - b > 0:
      return (r1 - l1) * (t1 - b1) + (r2 - l2) * (t2 - b2) - (r - l) * (t - b)

    # otherwise return area of rec1 + area of rec2
    return (r1 - l1) * (t1 - b1) + (r2 - l2) * (t2 - b2)