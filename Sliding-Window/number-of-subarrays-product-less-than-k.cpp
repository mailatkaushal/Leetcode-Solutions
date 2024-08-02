class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& A, int k) {
    if (k<=1) return 0;
    int ans=0;
    int prod=1;
    for (int i=0,j=0; j<A.size(); ++j) {
      prod*=A[j];
      while (prod>=k) prod/=A[i++];
      ans+=j-i+1;
    }
    return ans;
  }
};