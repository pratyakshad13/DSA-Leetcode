class Solution {
private:
    int solve(int pos,int canBuy,vector<int>& prices,vector<vector<int>> & dp){
        if( pos >= prices.size()){
            return 0;
        }
        if(dp[pos][canBuy] != -1){
            return dp[pos][canBuy];
        }
        int profit;
        if(canBuy){
            int purchased = -prices[pos] + solve( pos + 1,0,prices,dp);
            int notPurchased = solve(pos + 1,1,prices,dp);
            profit = max(purchased,notPurchased);
        }
        else{
            int sold = prices[pos] + solve( pos + 1,1,prices,dp);
            int hold = solve(pos + 1,0,prices,dp);
            profit = max(sold,hold);
        }
        return dp[pos][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
