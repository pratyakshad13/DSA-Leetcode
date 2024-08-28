class Solution {
private:
    void swap( vector<int> & nums, int i , int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }

    void getAllThePermutations(vector<int> & nums,set<vector<int>> & st, int pos){
        if( pos >= nums.size()){
            st.insert(nums);
            return;
        }
        for( int i = pos ; i < nums.size() ; i++){
            swap(nums,pos,i);
            getAllThePermutations(nums,st,pos + 1);
            swap(nums,pos,i);
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        getAllThePermutations(nums,st,0);

        for(auto element : st){
            ans.push_back(element);
        }

        return ans;
    }
};
