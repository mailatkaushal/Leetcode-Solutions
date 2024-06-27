class Solution {
public:
  void sortColors(vector<int>& A) {
    int i=0;
    int j=0;
    int k=A.size()-1;
    while (j <= k) {
      if (A[j] == 0) {
        swap(A[i], A[j]);
        ++i;
        ++j;
      }
      else if (A[j] == 1) ++j;
      else {
        swap(A[j], A[k]);
        --k;
      }
    }
  }
};