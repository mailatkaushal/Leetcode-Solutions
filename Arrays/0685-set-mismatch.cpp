// Time: o(n)
// Space: O(1)

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int dup = -1;
    int mis = -1;

    for (int& num : nums) {
      int idx = abs(num)-1;
      if (nums[idx] < 0) 
        dup = abs(num);
      else 
        nums[idx] = -nums[idx];
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        mis = i+1;
        break;
      }
    }

    return {dup, mis};
  }
};

// a-7