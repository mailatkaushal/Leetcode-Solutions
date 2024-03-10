# Time  : O(n^2)
# Space : O(n^2)

class Solution:
  def generate(self, rows: int) -> List[List[int]]:
    triangle = [[1]]

    for i in range(1, rows):
      row = [1] * (i + 1)
      for j in range(1, i):
        row[j] = triangle[i-1][j-1] + triangle[i-1][j]
      triangle.append(row)
    
    return triangle

    '''
    rows = 5

    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1

    '''