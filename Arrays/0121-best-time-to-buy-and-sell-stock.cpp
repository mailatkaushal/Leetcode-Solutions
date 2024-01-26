// Time: o(n)
// Space: O(1)

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i-1])
        maxProfit = max(maxProfit, prices[i] - minPrice);
      else 
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
  }
};

// Time: o(n)
// Space: O(1)

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int i = 0, j = 1;
    
    while (j < prices.size()) {
      if (prices[i] < prices[j]) 
        maxProfit = max(maxProfit, prices[j] - prices[i]);
      else 
        i = j;
      j++;
    }

    return maxProfit;
  }
};