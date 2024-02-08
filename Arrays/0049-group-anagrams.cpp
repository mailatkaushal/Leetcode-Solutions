// Time  : O(n*klogk) - where k is max length of string
// Space : O(n*k)

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> ump;

    for (auto& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      ump[key].push_back(str);
    }

    for (auto& [key, anagrams] : ump) {
      res.push_back(anagrams);
    }

    return res;
  }
};

// Time  : O(n*k)
// Space : O(n*k)

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> ump;

    for (auto& str : strs) {
      string key = sortStr(str);
      ump[key].push_back(str);
    }

    vector<vector<string>> res;
    res.reserve(ump.size());

    for (auto& [key, anagrams] : ump) 
      res.push_back(anagrams);

    return res;
  }

  string sortStr(string& s) {
    vector<int> v(26);
    for (char& c : s) 
      ++v[c - 'a'];

    string sorted;
    sorted.reserve(s.size());

    for (int i = 0; i < 26; ++i) {
      if (v[i] > 0)
        sorted += string(v[i], i + 'a');
    }

    return sorted;
  } 
};