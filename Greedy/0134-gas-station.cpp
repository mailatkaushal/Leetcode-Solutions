// Bruteforce - TLE
// Time  : O(n^2)
// Space : O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    for (int i = 0; i < n; ++i) {
      int fuel = 0;
      int cnt = 0;
      int j = i;

      for (int j = i; cnt < n; ++j) {
        fuel += gas[j % n] - cost[j % n];
        if (fuel >= 0) 
          ++cnt;
        else
          break;
      }

      if (cnt == n) 
        return i;
    }

    return -1;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum_gas = accumulate(gas.begin(), gas.end(), 0);
    int sum_cost = accumulate(cost.begin(), cost.end(), 0);

    if (sum_gas < sum_cost)
      return -1;

    int total = 0;
    int res = 0;

    for (int i = 0; i < gas.size(); ++i) {
      total += gas[i] - cost[i];
      if (total < 0) {
        total = 0;
        res = i + 1;
      }
    }

    return res;
  }
};