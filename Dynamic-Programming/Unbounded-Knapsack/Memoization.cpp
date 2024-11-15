class Solution {
  private:
    int solve( int index,int sum,int capacity,vector<int> & val,vector<int> & wt,vector<vector<int>> & dp){
        
        if( index >= val.size() || sum > capacity){
            return 0;
        }
        
        if( sum == capacity ){
            return 0;
        }
        
        if( dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        int include = 0,notInclude;
        
        if(wt[index] + sum <= capacity ){
            include = solve(index , sum + wt[index],capacity,val,wt,dp) + val[index];
        }
        
        notInclude = solve( index + 1, sum ,capacity,val,wt,dp);
        
        return dp[index][sum] = max(include,notInclude);
    }
  public:
    int knapSack(int capacity, vector<int>& val, vector<int>& wt) {
        
        vector<vector<int>> dp(val.size(),vector<int>( capacity + 1 , -1));
        
        return solve(0,0,capacity,val,wt,dp);
    }
};
