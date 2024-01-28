// Time: o(n)
// Space: O(n)

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> ump;
    ump[0] = 1;
    int sum = 0;
    
    for (int& num : nums) {
      sum += num;
      if (ump.find(sum - k) != ump.end()) 
        res += ump[sum - k];
      ump[sum]++;
    }

    return res;
  }
};