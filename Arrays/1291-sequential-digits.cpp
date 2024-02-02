// Time  : O(9*8) ~ O(1)
// Space : O(1)

class Solution {
public:
  vector<int> sequentialDigits(int& low, int& high) {
    vector<int> res;
    queue<int> que;
    
    for (int i = 1; i <= 8; ++i)
      que.push(i);

    while (!que.empty()) {
      int num = que.front();
      que.pop();

      if (low <= num && num <= high) 
        res.push_back(num);

      int last_digit = num % 10;
      if (last_digit < 9)  // num = 123, 3 < 9 
        que.push(num * 10 + (last_digit + 1));  // 123 -> 1230 + 4
    }

    return res;
  }
};

// Time  : O(36) ~ O(1)
// Space : O(1)

class Solution {
public:
  vector<int> sequentialDigits(int& low, int& high) {
    vector<int> allPossible = {
      12, 23, 34, 45, 56, 67, 78, 89,
      123, 234, 345, 456, 567, 678, 789,
      1234, 2345, 3456, 4567, 5678, 6789,
      12345, 23456, 34567, 45678, 56789,
      123456, 234567, 345678, 456789,
      1234567, 2345678, 3456789,
      12345678, 23456789,
      123456789
    };

    vector<int> res;

    for (int i = 0; i < allPossible.size(); ++i) {
      if (allPossible[i] < low)
        continue;
        
      if (allPossible[i] > high)
        break;
        
      res.push_back(allPossible[i]);
    }

    return res;
  }
};