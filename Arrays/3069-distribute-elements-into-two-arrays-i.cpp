// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> resultArray(vector<int>& A) {
    vector<int> a = {A[0]}, b = {A[1]};

    for (int i = 2; i < A.size(); ++i) {
      if (a.back() > b.back())
        a.push_back(A[i]);
      else
        b.push_back(A[i]);
    }

    for (int& n : b) 
      a.push_back(n);

    return a;
  }
};