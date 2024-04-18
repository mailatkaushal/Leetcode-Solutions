// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  int minimumMultiplications(vector<int>& A, int start, int end) {
    vector<int> dist(1e5, 1e9);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    int steps = 0;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        int u = q.front();
        q.pop();
        if (u == end) return steps;
        for (int& a : A) {
          int v = (u * a) % 100000;
          if (steps + 1 < dist[v]) {
            dist[v] = steps + 1;
            q.push(v);
          }
        }
      }
      ++steps;
    }
    return -1;
  }
};