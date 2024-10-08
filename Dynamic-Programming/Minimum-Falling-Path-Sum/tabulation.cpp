class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for( int i = 0 ; i < n ; i++){
            dp[ n- 1][i] = matrix[n - 1][i];
        }

        for( int row = n - 2 ; row >= 0 ; row--){
            for( int col = 0 ; col < n ; col++){
                if(col - 1 <0){
                    dp[row][col] = min(dp[row + 1][col],dp[row + 1][col + 1]) + matrix[row][col];
                }
                else if( col + 1 == n ){
                    dp[row][col] = min(dp[row + 1][col],dp[row + 1][col - 1]) + matrix[row][col];
                }

                else{
                    dp[row][col] = min(dp[row + 1][col],min(dp[row + 1][col - 1] ,dp[row + 1][col + 1]))+ matrix[row][col];
                }
            }
        }

        int ans = INT_MAX;

        for( int i= 0 ; i < n ; i++){
            ans = min(ans,dp[0][i]);
        }

        return ans;
    }
};
