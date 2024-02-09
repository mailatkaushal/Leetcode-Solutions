// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int minimumPushes(string& word) {
    sortStr(word);  // decreasing frequency

    vector<int> v(8);  // total keys : 8
    int res = 0;
    int k = 0;  // idx : 0 -> 7
    vector<int> cache(26, -1); 

    for (char& c : word) {
      if (cache[c - 'a'] == -1) {
        v[k]++;
        cache[c - 'a'] = v[k];
        res += v[k];
        ++k;
      }
      else 
        res += cache[c - 'a'];

      if (k == 8)
        k = 0;
    }

    return res;
  }

  // Using bucket sort
  // time : O(n) & space : O(n)
  void sortStr(string& word) {
    int n = word.size();
    vector<int> v(26);

    for (char& c : word)
      ++v[c - 'a'];
      
    vector<vector<char>> bucket(n+1);

    for (int i = 0; i < 26; ++i) {
      if (v[i] > 0)
        bucket[v[i]].push_back(i + 'a');
    }

    word = "";

    for (int freq = n; freq >= 0; --freq) {
      for (char& c : bucket[freq])
        word += string(freq, c);
    }
  }
};

// Time  : O(n + 26log26)
// Space : O(log26)

class Solution {
public:
  int minimumPushes(string& word) {
    vector<int> v(26);
    for (char& c : word) 
      ++v[c - 'a'];
    
    sort(v.rbegin(), v.rend());

    int res = 0;
    for (int i = 0; i < 26; ++i) 
      res += v[i] * (1 + i/8);

    return res;
  }
};