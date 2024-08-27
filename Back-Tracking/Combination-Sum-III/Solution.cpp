class Solution {
private:
    void getAllCombinations(int k, int n, vector<vector<int>> & ans, int sum, int num,vector<int> temp){

        if( k == 0 ){
            if( sum == n ){
                ans.push_back( temp);
            }
            return;
        }
        if( num > 9){
            return;
        }

        temp.push_back(num);
        getAllCombinations(k - 1,n,ans,sum + num , num + 1,temp);
        temp.pop_back();
        getAllCombinations(k,n,ans,sum, num + 1,temp);
    

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        getAllCombinations(k,n,ans,0,1,{});
        return ans;
    }
};
