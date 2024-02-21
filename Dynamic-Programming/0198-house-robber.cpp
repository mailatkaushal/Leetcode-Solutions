// Time:  O(n)
// Space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    int rob1 = 0, rob2 = 0;
    
    for (int& num: nums) {
      int tmp = max(rob1 + num, rob2);
      rob1 = rob2;
      rob2 = tmp;
    }

    return rob2;
  }
};