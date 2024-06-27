class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& x) {
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;
    while (i < n && intervals[i][1] < x[0]) ans.push_back(intervals[i++]);
    while (i < n && intervals[i][0] <= x[1]) {
      x[0] = min(intervals[i][0], x[0]);
      x[1] = max(intervals[i++][1], x[1]);
    }
    ans.push_back(x);
    while (i < n) ans.push_back(intervals[i++]);
    return ans;
  }
};