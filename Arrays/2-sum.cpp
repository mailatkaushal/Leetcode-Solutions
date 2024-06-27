class Solution {
public:
  vector<int> twoSum(vector<int>& A, int& target) {
    unordered_map<int, int> ump;
    for (int i = 0; i < A.size(); ++i) {
      int diff = target - A[i];
      if (ump.find(diff) != ump.end()) 
        return {ump[diff], i};
      ump[A[i]] = i;
    }
    return {};
  }
};