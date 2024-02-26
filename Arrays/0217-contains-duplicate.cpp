// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  bool containsDuplicate(vector<int>& A) {
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 1; i++) 
      if (A[i] == A[i+1]) 
        return true;

    return false;  
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool containsDuplicate(vector<int>& A) {
    set<int> st;

    for (int& num : A) {
      if (st.contains(num)) 
        return true;
      st.insert(num);
    }

    return false;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool containsDuplicate(vector<int>& A) {
    unordered_map<int, int> ump;
    for (int& num : A) 
      ++ump[num];
    
    for (auto& [key, freq] : ump) 
      if (freq > 1) 
        return true;
        
    return false;
  }
};