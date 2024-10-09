class Solution{   
private:
    int solve(vector<int> & arr,vector<vector<int>> & dp,int index,int target){
        if( target == 0){
            return 1;
        }
        if( target < 0 ){
            return 0;
        }
        
        if( index >= arr.size() ){
            return 0;
        }
        if( dp[index][target] != -1){
            return dp[index][target];
        }
        
        int takeThisElement = solve(arr,dp, index + 1, target - arr[index]);
        int dontTakeThisElement = solve(arr,dp, index + 1, target );
        
        return dp[index][target] = takeThisElement || dontTakeThisElement;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum + 1, -1));
        return dp[0][sum] =  solve(arr,dp, 0 , sum);
    }
};
