// Time  : O(nlogn)
// Space : O(1)

class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int max_score = 0;
    int score = 0;
    int l = 0, r = tokens.size() - 1;

    // losi power -> choose smallest token
    // gain power -> choose largest token

    while (l <= r) {
      if (power >= tokens[l]) { 
        power -= tokens[l++];  // Choosing the smallest token as, regardless of the token, the score only increments by one 
        max_score = max(max_score, ++score); 
      }
      else if (score > 0) {
        --score;
        power += tokens[r--];  // Choosing the largest token to get the maximum increase in power
      }
      else 
        break; // If no more moves are possible
    }

    return max_score;
  }
};