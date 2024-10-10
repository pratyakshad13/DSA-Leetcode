class Solution {
private:
    bool solve(vector<int> & nums,vector<vector<int>> & dp,int sum , int index){
        if( index >= nums.size() || sum < 0){
            return false;
        }

        if( sum == 0 ){
            return dp[index][sum] = true;
        }

        if( dp[index][sum] != -1){
            return dp[index][sum];
        }

        int takeIt = solve( nums,dp,sum - nums[index],index + 1);
        int notTakeIt = solve(nums,dp,sum,index + 1);

        return dp[index][sum] = takeIt || notTakeIt;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1){
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2 + 1, -1));

        return solve(nums,dp,sum/2,0);
    }
};
