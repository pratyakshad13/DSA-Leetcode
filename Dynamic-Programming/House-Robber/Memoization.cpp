class Solution {
private:
    int getAns(vector<int> & nums,vector<int> & dp, int pos){
        if(pos == 0){
            return dp[pos] = nums[pos];
        }

        if( pos < 0 ){
            return 0;
        }
        if( dp[pos] != -1){
            return dp[pos];
        }

        int robbedThisHouse = nums[pos] + getAns(nums,dp,pos - 2);
        int notRobbedThisHouse = getAns(nums,dp,pos - 1);

        return dp[pos] = max(robbedThisHouse,notRobbedThisHouse);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);

        getAns(nums,dp,nums.size() - 1);
        return dp[nums.size() - 1];
    }
};
