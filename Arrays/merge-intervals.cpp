class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& I) {
    sort(I.begin(), I.end());
    vector<vector<int>> ans = {I[0]};
    for (int i=1; i<I.size(); ++i) {
      if (ans.back()[1] >= I[i][0]) ans.back()[1] = max(ans.back()[1], I[i][1]);
      else ans.push_back(I[i]);
    }
    return ans;
  }
};