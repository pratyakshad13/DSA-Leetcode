Backtracking Approach


class Solution {
private:
    int getMaxUncrossedLines(vector<int>& nums1, vector<int>& nums2,int i , int j){
        if( i >= nums1.size() || j >= nums2.size()){
            return 0;
        }
        if( nums1[i] == nums2[j]){
            return getMaxUncrossedLines(nums1,nums2,i+1,j+1) + 1;
        }

        int x = getMaxUncrossedLines(nums1,nums2,i,j+1);
        int y = getMaxUncrossedLines(nums1,nums2,i+1,j);

        return max(x,y);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        return getMaxUncrossedLines(nums1,nums2,0,0);
    }
};
