// time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& A, int& k) {
    int n = A.size();
    vector<int> res(n - k + 1);
    deque<int> dq; // decreasing -> headmost element in deque is the index of largest number in sliding window
    
    for (int i = 0; i < n; ++i) {
      // discard the number outside window range, window size can't exceed k
      if (!dq.empty() && dq.front() == i - k)
        dq.pop_front();

      // remove smaller numbers
      while (!dq.empty() && A[dq.back()] < A[i])
        dq.pop_back();

      // although current number may not be the largest in the window, it may be useful when larger elements in the window are popped
      dq.push_back(i);

      // start to construct res vector when we first see k elements
      if (i >= k - 1)
        //window range: i - (k - 1), ... , i
        res[i - (k - 1)] = A[dq.front()];
    }

    return res;
  }
};