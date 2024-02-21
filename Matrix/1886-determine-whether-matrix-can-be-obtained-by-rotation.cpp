class Solution:
  def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
    # check for 0, 90, 180, 270 degrees
    
    n = len(mat)

    if mat == target:  # rotaion by 0 degree
      return True

    for i in range(3):  # rotation by 90, 180, 270 degrees
      # reverse each row
      start, end = 0, n - 1
      while start < end:
        for i in range(n):
          mat[start][i], mat[end][i] = mat[end][i], mat[start][i]
        start += 1
        end -= 1

      # Transpose the matrix (swap non-diagonal elements)
      for i in range(n):
        for j in range(i):
          mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

      if mat == target:
        return True

    return False