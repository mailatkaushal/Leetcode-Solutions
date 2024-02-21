// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& A) {
    // res[i] is equal to the product of all elements of A except A[i]
    int n = A.size();
    vector<int> res(n, 1), L(n, 1), R(n, 1);

    for (int i = 1; i < n; ++i) 
      L[i] = L[i-1] * A[i-1];

    for (int i = n-2; i >= 0; --i) 
      R[i] = R[i+1] * A[i+1];

    for (int i = 0; i < n; ++i) 
      res[i] = L[i] * R[i];
    
    return res; 
  }
};

// Time  : O(n)
// Space : O(1) given in ques - The output array does not count as extra space for space complexity analysis 

class Solution:
  def productExceptSelf(self, A: List[int]) -> List[int]:
    n = len(A)
    res = [1] * n

    for i in range(n - 2, -1, -1):
      res[i] = res[i+1] * A[i+1]

    left = 1

    for i in range(n):
      res[i] *= left
      left *= A[i]

    return res