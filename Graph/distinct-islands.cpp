class Solution {
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string> st;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    string s = "x";
                    grid[i][j] = 0;
                    queue<pair<int,int>> q; q.push({i,j});
                    while (!q.empty()) {
                        auto p = q.front(); q.pop();
                        int x = p.first;
                        int y = p.second;
                        for (auto& dir : dirs) {
                            int nx = x+dir[0];
                            int ny = y+dir[1];
                            if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1) {
                                s += "_" + to_string(nx-i) + "_" + to_string(ny-j);
                                grid[nx][ny] = 0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    st.insert(s);
                }
            }
        }
        return st.size();
    }
};