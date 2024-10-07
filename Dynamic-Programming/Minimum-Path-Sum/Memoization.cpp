class Solution {
private:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row >= m || col >= n){
            return INT_MAX;
        }

        if( row == m - 1 && col == n - 1){
            return grid[row][col];
        }
        if( dp[row][col] != -1){
            return dp[row][col];
        }

        int downAns = solve(grid,dp,row + 1, col);
        int rightAns = solve(grid,dp, row , col + 1);

        return dp[row][col] = min(downAns , rightAns) + grid[row][col];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(grid,dp,0,0);

    }
};
