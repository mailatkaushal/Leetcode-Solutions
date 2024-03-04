// Time  : O(numRows*n)
// Space : O(numRows*n)

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    int n = s.size();
    vector<vector<char>> zz(numRows, vector<char> (n, ' '));
    int row = 0;
    int col = 0;
    bool down = false;

    for (char& c : s) {
      zz[row][col] = c;
      if (row == 0 || row == numRows - 1)
        down = !down;
      if (down)
        ++row;
      else 
        --row;
        ++col;
    }

    string res;

    for (auto& v : zz) 
      for (char& c : v) 
        if (c != ' ') {
          res += c;
          if (res.size() == n)
            break;
        }

    return res;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  string convert(string s, int numRows) {
    // Edge case
    if (numRows == 1)
      return s;

    vector<string> zz(numRows);
    int row = 0;
    bool flag = false;

    for (char& c : s) {
      zz[row] += c;
      if (row == 0 || row == numRows - 1)
        flag = !flag;
      if (flag)
        ++row;
      else
        --row;
    }

    string res;
    
    for (string& str : zz)
      res += str;

    return res;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  string convert(string s, int numRows) {
    // Edge case
    if (numRows == 1)
      return s;

    string zz;

    for (int row = 0; row < numRows; ++row) {
      // for each row the next char is at idx 2 * (numRows - 1)
      int increment = 2 * (numRows - 1);
      for (int i = row; i < s.size(); i += increment) {
        zz += s[i];
        // For middle rows there will be extra chars
        if (row > 0 && row < numRows - 1 && i + increment - 2 * row < s.size()) 
          zz += s[i + increment - 2 * row];
      }
    }

    return zz;
  }
};