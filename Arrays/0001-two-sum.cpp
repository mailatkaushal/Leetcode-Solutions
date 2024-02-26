// Time  : O(n^2)
// Space : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
      int n = A.size()
      vector<int> res(2);

      for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
          if (A[i] + A[j] == target) {
            res[0] = i;
            res[1] = j;
            break;
          }

      return res;
    }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> twoSum(vector<int>& A, int& target) {
    // At each num, calculate diff, if exists in hash map then return
    
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