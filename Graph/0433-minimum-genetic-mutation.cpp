// Time  : O(4^8)
// Space : O(4^8)
class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> ba(bank.begin(), bank.end());
    unordered_set<string> vis;
    vis.insert(startGene);
    queue<string> q;
    q.push(startGene);
    int ans = 0;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        auto x = q.front();
        q.pop();
        if (x == endGene) return ans;
        for (char& c : x) {
          char prev = c;
          for (char ch : "ACGT") {
            c = ch;
            if (vis.find(x) == vis.end() && ba.find(x) != ba.end()) {
              vis.insert(x);
              q.push(x);
            }
          }
          c = prev;
        }
      }
      ++ans;
    }
    return -1;
  }
};