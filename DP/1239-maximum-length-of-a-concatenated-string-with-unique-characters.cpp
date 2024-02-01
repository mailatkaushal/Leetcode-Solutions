// Time:  O(n*2^n)
// Space: O(1)

class Solution {
public:
  int maxLength(vector<string>& arr) {
    return dfs(arr, 0, "");
  }

  int dfs(vector<string>& arr, int i, string s) {
    if (i == arr.size())
      return s.size();
      
    int include = 0, exclude = 0;

    if (hasDuplicate(s, arr[i])) 
      exclude = dfs(arr, i+1, s);
    else {
      exclude = dfs(arr, i+1, s);
      include = dfs(arr, i+1, s += arr[i]);
    }

    return max(include, exclude);
  }

  bool hasDuplicate(string& a, string& b) {
    vector<int> v(26, 0);

    for (char& c : a) {
      ++v[c - 'a'];
      if (v[c - 'a'] > 1) 
        return true;
    }

    for (char& c : b) {
      ++v[c - 'a'];
      if (v[c - 'a'] > 1) 
        return true;
    }

    return false;
  }
};