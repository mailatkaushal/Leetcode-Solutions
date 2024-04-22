// Time  : O(10^4)
// Space : O(10^4)
class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> vis;
    vis.insert("0000");
    queue<string> q;
    q.push("0000");
    int turns = 0;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        auto x = q.front();
        q.pop();
        if (x == target) return turns;
        if (dead.find(x) != dead.end()) continue;
        for (char& c : x) {
          char l = c == '0' ? '9' : c-1;
          char r = c == '9' ? '0' : c+1;
          char pehle = c;
          c = l;
          if (vis.find(x) == vis.end()) {
            vis.insert(x);
            q.push(x);
          }
          c = r;
          if (vis.find(x) == vis.end()) {
            vis.insert(x);
            q.push(x);
          }
          c = pehle;
        }
      }
      ++turns;
    }
    return -1;
  }
};