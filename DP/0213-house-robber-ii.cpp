// Time: O(n)
// Space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) 
      return nums[0];
    
    return max(f(nums, 0, n-2), f(nums, 1, n-1));
  }

  int f(vector<int>& nums, int l, int r) {
    int rob1 = 0, rob2 = 0;

    for (int i = l; i <= r; ++i) {
      int tmp = max(rob1 + nums[i], rob2);
      rob1 = rob2;
      rob2 = tmp;
    }
    
    return rob2;
  }
};

// a-4
