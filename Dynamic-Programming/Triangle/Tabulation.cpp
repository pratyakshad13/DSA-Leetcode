class Solution {
private: 
    void solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        int m = grid.size();

        
        for( int col = 0 ; col < m ; col++){
            dp[m - 1][col] = grid[m - 1][col];
        }

        for( int row = m - 2 ; row >= 0 ; row--){
            for( int col = 0 ; col < row + 1 ; col++){
                dp[row][col] = min(dp[row + 1][col],dp[row + 1][col + 1]) + grid[row][col];
            }
        }
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp;
        for(int i = 0 ; i < m ; i++){
            vector<int> temp;
            for( int j = 0 ; j <= i ; j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }

        solve(triangle,dp,0,0);

        return dp[0][0];
    }
};
