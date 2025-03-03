class Solution {   
public: 
    vector<int> spirallyTraverse(vector<vector<int>>& M, int m, int n) {
        vector<int> ans;
        int t = 0, b = m-1;
        int l = 0, r = n-1;
        while (t <= b && l <= r) {
            for (int j = l; j <= r; ++j) ans.push_back(M[t][j]);
            t++;
            for (int i = t; i <= b; ++i) ans.push_back(M[i][r]);
            --r;
            if (t <= b) {
                for (int j = r; j >= l; --j) ans.push_back(M[b][j]);
                --b;
            }
            if (l <= r) {
                for (int i = b; i >= t; --i) ans.push_back(M[i][l]);
                ++l;
            }
        }
        return ans;
    }
};