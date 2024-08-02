class Solution {
public:
  int atMostSum(vector<int>& A, int k) {
    if (k<0) return 0;
    int ans=0;
    int sum=0;
    for (int i=0,j=0; j<A.size(); ++j) {
      sum+=A[j];
      while (sum>k) {
        sum-=A[i];
        ++i;
      }
      ans+=j-i+1;
    }
    return ans;
  }
  int numSubarraysWithSum(vector<int>& A, int k) {
    return atMostSum(A,k)-atMostSum(A,k-1);
  }
};