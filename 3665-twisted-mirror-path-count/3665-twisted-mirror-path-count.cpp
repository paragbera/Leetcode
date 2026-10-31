class Solution {
public:

    int md = 1e9 + 7;
    
    int dfs(int i, int j, int flag, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

        int n = grid.size();
        int m = grid[0].size();

        if(i == n - 1 && j == m - 1) return dp[i][j][flag] = 1;

        if (i < 0 || j < 0 || i >= n || j >= m) return 0;

        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        if(grid[i][j] == 0){

            int right = 0;

            if(j + 1 < m){
                right = dfs(i, j + 1, 1, grid, dp) % md;
            }

            int down = 0;

            if(i + 1 < n){
                down = dfs(i + 1, j, 0, grid, dp) % md;
            }

            return dp[i][j][flag] = (right + down) % md;

        }

        else{
            
            int r = 0;

            int d = 0;

            if(flag == 1){

                r = dfs(i + 1, j, 0, grid, dp) % md;
            }

            else{
                d = dfs(i, j + 1, 1, grid, dp) % md;
            }

            return dp[i][j][flag] = (r + d) % md;
        }

        return 0;
    }


    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1)));
        
        return dfs(0, 0, 0, grid, dp) % md;
    }
};