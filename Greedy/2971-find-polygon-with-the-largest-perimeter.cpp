// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  long long largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end());
    
    long long sum = 0;
    for (int& i : A)
      sum += i;

    for (int k = A.size() - 1; k >= 2; --k) {
      sum -= A[k];
      if (sum > A[k]) 
        return sum + A[k];
    }

    return -1;
  }
};

// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  long long largestPerimeter(vector<int>& v) {
    sort(v.begin(), v.end());
    
    long long sum = 0;
    for (int& i : v)
      sum += i;

    for (int k = v.size() - 1; k >= 2; --k) {
      sum -= v[k];
      if (sum > v[k]) 
        return sum + v[k];
    }

    return -1;
  }
};