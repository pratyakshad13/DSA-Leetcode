class Solution{
  int mod = 1e9 + 7;
    private:
    int solve(vector<vector<int>> & dp,int arr[],int n,int target,int index){
        if( target == 0){
            return dp[index][target] = 1;
        }
        if( index >= n || target < 0){
            return 0;
        }
        if( dp[index][target] != -1){
            return dp[index][target];
        }
        
        
        int pickIt = solve(dp,arr,n,target - arr[index],index + 1) % mod;
        int notPickIt = solve( dp,arr,n, target,index + 1) % mod;
        return dp[index][target] = (pickIt + notPickIt) % mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    sort(arr,arr+n); //As the array may contain 0;
	    vector<vector<int>> dp(n + 1,vector<int>(sum + 1,-1));
        return solve(dp,arr,n,sum,0);
	}
};
