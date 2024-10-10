class Solution {
private:
    bool solve(vector<int> & nums,int sum , int index){
        if( index >= nums.size() || sum < 0){
            return false;
        }

        if( sum == 0 ){
            return true;
        }

        int takeIt = solve( nums,sum - nums[index],index + 1);
        int notTakeIt = solve(nums,sum,index + 1);

        return takeIt || notTakeIt;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1){
            return false;
        }

        return solve(nums,sum/2,0);
    }
};
