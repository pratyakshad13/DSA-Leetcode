class Solution {
public:
    int pivot_index(vector<int>& nums){
        int start=0,end=nums.size()-1;

        while(start<end){
            int mid=start+(end-start)/2;
            if(mid==0)return 0;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]>nums[start]){
                start=mid;
            }
            else end=mid;
        }
        return -1;
    }

    int bin_search(vector<int>& nums,int start,int end,int key){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==key) return mid;
            else if(nums[mid]>key) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=pivot_index(nums);
        int ans=bin_search(nums,0,index,target);
        if(ans==-1){
            ans=bin_search(nums,index+1,nums.size()-1,target);
        }
        return ans;
        

    }  
};
