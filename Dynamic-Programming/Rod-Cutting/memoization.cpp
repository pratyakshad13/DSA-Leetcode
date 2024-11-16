class Solution{
  private: 
    int solve(int index,int currLength,int price[], int n,vector<vector<int>>& dp){
        if( index >= n){
            return INT_MIN;
        }
        if( currLength == n){
            return 0;
        }
        if(dp[index][currLength] != -1){
            return dp[index][currLength];
        }
        
        int takeThis = INT_MIN;
        int dontTakeThis = solve(index + 1,currLength,price,n,dp);
        if(currLength + index + 1 <= n){
            takeThis = solve(index,currLength + index + 1,price , n , dp) + price[index];
        }
        return dp[index][currLength] = max(takeThis,dontTakeThis);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n + 1,0));
        return solve(0,0,price,n,dp);
    }
};
