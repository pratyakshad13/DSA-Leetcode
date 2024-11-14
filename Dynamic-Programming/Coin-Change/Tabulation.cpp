class Solution {
private:
    int solve( int index, vector<int> & coins, int amount,vector<vector<int>> & dp){

        int n = coins.size();

        if( index == n - 1){
            if( amount%coins[n -1] == 0 ){
                return dp[index][amount] =  amount/coins[n -1];
            }
            return dp[index][amount] = 1e9;
        }

        if( amount == 0){
            return 0;
        }
        if( dp[index][amount] != -1){
            return dp[index][amount];
        }

        int include = 1e9, includeAndMoveForward = 1e9;
        if(amount - coins[index]>=0) {
            include = solve(index , coins,amount - coins[index],dp) + 1;
            // includeAndMoveForward = solve(index + 1, coins,amount - coins[index],dp ) + 1;
        }
        int dontInclude = solve( index + 1, coins, amount,dp);
        
        return dp[index][amount] = min(include,dontInclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1,-1));
        
        for( int i = 0 ; i <= amount ; i++ ){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for( int i = 1 ; i < coins.size(); i++){
            dp[i][0] = 0;
        }

        for( int i = 1 ; i < coins.size() ; i++){
            for( int j = 1 ; j <= amount ; j++){

                int include = 1e9;
                if(j  >= coins[i]) {
                    include = dp[i][j - coins[i]] + 1;

                }
                int dontInclude = dp[i - 1][j];
        
                dp[i][j] = min(include,dontInclude);

            }
        }

        return dp[coins.size() - 1][amount] == 1e9 ? -1 : dp[coins.size() - 1][amount];
        
    }
};
