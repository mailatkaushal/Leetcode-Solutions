// Time  : O(n)
// Space : O(k)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& A, int k) {
    int n = A.size();
    int x = 0;
    vector<int> res(n-k+1);
    deque<int> dq;  // monotonic decreasing / always decreasing

    for (int i = 0; i < n; ++i) {
      // pop left value from dq which is out of window size
      if (!dq.empty() && dq.front() == i-k) 
        dq.pop_front();
      
      // pop smaller values from dq
      while (!dq.empty() && A[dq.back()] < A[i])
        dq.pop_back();

      dq.push_back(i);

      // Only when the window size first gets equal or greater than k
      if (i + 1 >= k)
        res[x++] = A[dq.front()];  // front - max element
    }

    return res;
  }
};