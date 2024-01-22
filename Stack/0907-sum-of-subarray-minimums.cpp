// Time: O(n)
// Space: O(n)

typedef long long ll;
class Solution {
public:
  // finding next smaller element to left for each element
  vector<int> getNSL(vector<int>& arr, int& n) {
    vector<int> res(n);
    stack<int> stk;

    for (int i = 0; i < n; ++i) {
      if (stk.empty()) 
        res[i] = -1;
      else {
        while (!stk.empty() && arr[stk.top()] > arr[i])  // strictly less
          stk.pop();
        res[i] = stk.empty() ? -1 : stk.top();
      }
      stk.push(i);
    }

    return res;
  }

  // finding next smaller element to right for each element
  vector<int> getNSR(vector<int>& arr, int& n) {
    vector<int> res(n);
    stack<int> stk;

    for (int i = n-1; i >= 0; --i) {
      if (stk.empty()) 
        res[i] = n;
      else {
        while (!stk.empty() && arr[stk.top()] >= arr[i])  // non-strictly less
          stk.pop();
        res[i] = stk.empty() ? n : stk.top();
      }
      stk.push(i);
    }

    return res;
  }

  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int M = 1e9+7;

    vector<int> NSL = getNSL(arr, n);  // Next smaller to left
    vector<int> NSR = getNSR(arr, n);  // Next smaller to right

    ll sum = 0;

    for (int i = 0; i < n; ++i) {
      ll d1 = i - NSL[i];  // distance to nearest smaller to left from i
      ll d2 = NSR[i] - i;  // distance to nearest smaller to right from i

      /*
        We have d1 numbers in the left and d2 numbers in the right
        i.e. We have d1 options to start from the left of arr[i] 
        and d2 options to end in the right of arr[i]
        So the total options to start and end are d1*d2
      */
      
      ll sum_i  = arr[i] * d1*d2;
      sum = (sum + sum_i) % M;
    }

    return sum;
  }
};

// a-1