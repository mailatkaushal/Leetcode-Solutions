# Time  : O(m*n)
# Space : O(m+n)

class Solution:
  def setZeroes(self, M: List[List[int]]) -> None:
    # Do not return anything, modify matrix in-place instead.

    m, n = len(M), len(M[0])
    rows = [False] * m  # rows to set to 0
    cols = [False] * n  # cols to set to 0
    
    for i in range(m):
      for j in range(n):
        if M[i][j] == 0:
          rows[i] = True
          cols[j] = True

    for i in range(m):
      for j in range(n):
        if rows[i] == True or cols[j] == True:
          M[i][j] = 0

# Time  : O(m*n)
# Space : O(1)

class Solution:
  def setZeroes(self, M: List[List[int]]) -> None:
    # Do not return anything, modify matrix in-place instead.

    m, n = len(M), len(M[0])
    row_0 = False
    col_0 = False

    for i in range(m):
      if M[i][0] == 0:
        col_0 = True
        break

    for j in range(n):
      if M[0][j] == 0:
        row_0 = True
        break

    for i in range(1, m):
      for j in range(1, n):
        if M[i][j] == 0:
          M[i][0] = 0
          M[0][j] = 0

    for i in range(1, m):
      for j in range(1, n):
        if M[i][0] == 0 or M[0][j] == 0:
          M[i][j] = 0

    if row_0 == True:
      for j in range(n):
        M[0][j] = 0

    if col_0 == True:
      for i in range(m):
        M[i][0] = 0