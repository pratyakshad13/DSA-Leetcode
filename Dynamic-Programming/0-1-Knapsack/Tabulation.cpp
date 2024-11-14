
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity + 1,0));
        
        for (int i = 0; i <= capacity; i++) {
            if (i >= wt[0]) {
                dp[0][i] = val[0];
            }
        }
        
        for( int i = 1 ; i < n ; i++){
            for( int j = 1 ; j <= capacity ; j++){
                if(j>= wt[i])
                    dp[i][j] = max(dp[i-1][j] , dp[i - 1][j - wt[i]] + val[i]);
            
                else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        return dp[n - 1][capacity];
    }
};
