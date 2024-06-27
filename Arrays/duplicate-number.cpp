class Solution {
public:
  int findDuplicate(vector<int>& A) {
    int n = A.size();
    int ans;
    int slow = 0;
    int fast = 0;
    while (1) {
      slow = A[slow];
      fast = A[A[fast]];
      if (fast == slow) {
        fast = 0;
        while (fast != slow) {
          fast = A[fast];
          slow = A[slow];
        }
        ans = slow;
        break;
      }
    }
    return ans;
  }
};