class Solution {
public:
    set<pair<int, int>> st;

    vector<vector<int>> dir = {
        {1, 0}, {0, 1}, {0, -1}, {-1, 0}
    };

    int dfs(int i, int j, int cnt, vector<vector<int>>& grid) {

        st.insert({i, j});

        int n = grid.size();
        int m = grid[0].size();

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            cnt = 0;

        for (int d = 0; d < 4; d++) {
            int nr = i + dir[d][0];
            int nc = j + dir[d][1];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (grid[nr][nc] == 1)
                continue;

            if (st.count({nr, nc}))
                continue;

            if (dfs(nr, nc, cnt, grid) == 0)
                cnt = 0;
        }

        return cnt;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        st.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0 && !st.count({i, j})) {
                    ans += dfs(i, j, 1, grid);
                }
            }
        }

        return ans;
    }
};