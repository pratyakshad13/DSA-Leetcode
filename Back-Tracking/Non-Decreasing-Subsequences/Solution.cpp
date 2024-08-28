class Solution {
private:
    void allPossibleRequiredSubsequences(set<vector<int>> & st,vector<int>& nums,vector<int> temp,int pos,int prevElement){

        if( pos >= nums.size()){
            if(temp.size() > 1){
                st.insert(temp);
            }
            return;
        }

        if(nums[pos] >= prevElement){
            temp.push_back(nums[pos]);
            allPossibleRequiredSubsequences(st,nums,temp,pos + 1,nums[pos] );
            temp.pop_back();
            
        }
        allPossibleRequiredSubsequences(st,nums,temp,pos + 1, prevElement);
        // allPossibleRequiredSubsequences(st,nums,temp,pos + 1, );
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<vector<int>> ans;
       set<vector<int>> st;
       allPossibleRequiredSubsequences(st,nums,{},0, -101);
       for( auto element : st){
        ans.push_back(element);
       }
       return ans; 
    }
};
