// Time  : O(nlogn)
// Space : O(n)

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int n = deck.size();
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(i);
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
      A[q.front()] = deck[i];
      q.pop();
      q.push(q.front());
      q.pop();
    }
    return A;
  }
};