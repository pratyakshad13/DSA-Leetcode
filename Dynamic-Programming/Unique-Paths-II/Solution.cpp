class Solution {
private:
    void solve(vector<vector<int>> & grid,vector<vector<long long>> & dp){
        int m = grid.size();
        int n = grid[0].size();
        for( int row = m - 2 ; row >= 0 ; row--){
            for( int col = n - 2 ; col >= 0 ; col--){
                if(grid[row][col] == 1){
                    dp[row][col] = 0;
                }
                else{
                    dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
                }
            }
        }
        
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<long long >> dp(m,vector<long long>(n,-1));

        if( grid[m - 1][n - 1] == 1 || grid[0][0] == 1){
            return 0;
        }

        dp[m - 1][n - 1] = 1;

        for( int row = m - 2 ; row >= 0 ; row--){
            if( grid[row][n - 1] == 1){
                dp[row][n - 1] = 0;
            }
            else{
                dp[row][n - 1] = dp[row + 1][n - 1];
            }
        }

        for( int col = n - 2 ; col >= 0 ; col--){
            if( grid[m - 1][col] == 1){
                dp[m - 1][col] = 0;
            }
            else{
                dp[m - 1][col] = dp[m - 1][col + 1];
            }
        }
        solve(grid,dp);

        
        return dp[0][0];
    }
};
