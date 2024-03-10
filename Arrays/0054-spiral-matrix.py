# Time  : O(m * n)
# Space : O(m * n)

class Solution:
  def spiralOrder(self, M: List[List[int]]) -> List[int]:
    m, n = len(M), len(M[0])
    res = [0] * m * n
    x = 0
    t, b, l, r = 0, m - 1, 0, n - 1
    
    while t <= b and l <= r:
      for j in range(l, r + 1):
        res[x] = M[t][j]
        x += 1
      t += 1

      if t > b:
        break

      for i in range(t, b + 1):
        res[x] = M[i][r]
        x += 1
      r -= 1

      if l > r:
        break

      for j in range(r, l - 1, -1):
        res[x] = M[b][j]
        x += 1
      b -= 1

      if t > b:
        break

      for i in range(b, t - 1, -1):
        res[x] = M[i][l]
        x += 1
      l += 1

    return res