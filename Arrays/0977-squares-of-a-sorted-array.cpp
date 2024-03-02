// Time  : O(nlogn)
// Space : O(logn)

class Solution {
public:
  vector<int> sortedSquares(vector<int>& A) {
    for (int& a: A) 
      a *= a;
    
    sort(A.begin(), A.end());

    return A;
  }
};

# Time  : O(n)
# Space : O(n)

class Solution:
  def sortedSquares(self, A: List[int]) -> List[int]:
    # A is sorted in non-decreasing order -> Ex. [-1,0,1,1]
    # compare first and last element bc after square they have possibility of being the highest element
    # assign the highest square to last index of res 

    n = len(A)
    res = [0] * n
    i, j = 0, n - 1

    for k in range(n - 1, -1, -1):  # res index
      if abs(A[i]) >= abs(A[j]):
        res[k] = A[i] ** 2
        i += 1
      else:
        res[k] = A[j] ** 2
        j -= 1
    
    return res