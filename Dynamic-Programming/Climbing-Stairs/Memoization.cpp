class Solution {
private:
    int solve(int n , int k,vector<int>& dp){
        if(k>n){
            return 0;
        }
        if( k == n){
            return 1;
        }
        if( dp[k] != -1){
            return dp[k];
        }

        return dp[k] =  solve(n, k+1,dp) + solve(n,k+2,dp);

    }
public:
    int climbStairs(int n) {
        int k = 0;
        vector<int> dp(n+1,-1);
        return solve(n,k,dp);
    }
};
