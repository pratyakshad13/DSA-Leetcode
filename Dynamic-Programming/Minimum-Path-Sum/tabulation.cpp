class Solution {
private:
    void solve(vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        for( int row = m - 2 ; row >= 0 ; row--){
            for( int col = n -2 ; col >= 0 ; col--){
                dp[row][col] = min(dp[row + 1][col],dp[row][col + 1]) + grid[row][col];
            }
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for( int row = m -2 ; row >= 0 ; row--){
            dp[row][n - 1] = dp[row + 1][n - 1] + grid[row][n - 1];
        }

        for( int col = n -2 ; col >= 0 ; col--){
            dp[m - 1][col] = dp[m - 1][col + 1] + grid[m - 1][col];
        }

        solve(grid,dp);
        return dp[0][0];
    }
};
