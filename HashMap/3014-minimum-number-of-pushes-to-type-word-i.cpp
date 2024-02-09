// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int minimumPushes(string& word) {
    vector<int> v(8);  // total keys : 8
    int res = 0;
    int k = 0;  // idx : 0 -> 7

    for (int i = 0; i < word.size(); ++i) {
      v[k]++;  
      res += v[k];
      ++k; 
      if (k == 8) 
        k = 0;  
    }

    return res;
  }
};

// Time  : O(n + 26log26)
// Space : O(log26)

class Solution {
public:
  int minimumPushes(string& word) {
    vector<int> v(26);
    for (char& c : word) 
      v[c - 'a'] = 1;  // all chars in word are unique
    
    sort(v.rbegin(), v.rend());

    int res = 0;
    for (int i = 0; i < 26; ++i) 
      res += v[i] * (1 + i/8);

    return res;
  }
};