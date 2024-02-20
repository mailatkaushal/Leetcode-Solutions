// Time  : O(n)
// Space : O(1)

class Solution:
  def missingNumber(self, A: List[int]) -> int:
    # A containing distinct numbers in range [0, n] -> 1 missing
    n = len(A)
    sum = n * (n + 1) // 2  # sum of integers from 0 to n

    for i in range(len(A)):  
      sum -= A[i]  # Subtract each number in the A

    return sum  # The remaining value is the missing number

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int missingNumber(vector<int>& A) {
    int n = A.size();
    int res = n;

    for (int i = 0; i < n; i++) 
      res = res ^ i ^ A[i];
    
    return res;
  }
};