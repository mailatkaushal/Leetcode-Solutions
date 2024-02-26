# Time  : O(n^2)
# Space : O(1)

class Solution:
  def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
    n = len(bottomLeft)
    res = 0

    for i in range(n):
      for j in range(i+1, n):
        # find the edges of the overlaped area
        l = max(bottomLeft[i][0], bottomLeft[j][0])
        r = min(topRight[i][0], topRight[j][0])
        b = max(bottomLeft[i][1], bottomLeft[j][1])
        t = min(topRight[i][1], topRight[j][1])

        # if both edges are positive, it means that the overlap has positive area
        if r - l > 0 and t - b > 0:
          # side of the square that can fit inside the overlapped area
          s = min(r - l, t - b)
          res = max(res, s * s)

    return res