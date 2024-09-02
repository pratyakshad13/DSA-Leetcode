class Solution {
private: 
    void getAns(vector<string>& nums,map<string,int> & mp,string & ans,string temp,int pos){

        if( pos >= nums.size()){
            if(mp.count(temp) == 0){
                ans = temp;
            }
            return;
        }
        temp +='1';
        getAns(nums,mp,ans,temp,pos +1);
        if(ans.size() != 0){
            return;
        }
        temp.pop_back();
        temp +='0';
        getAns(nums,mp,ans,temp,pos + 1);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int> mp;
        for( int i = 0 ; i < nums.size() ; i++){
            if( mp.count(nums[i]) == 0){
                mp[nums[i]] = 1;
            }
        }

        string ans = "";
        getAns(nums,mp,ans,"",0);
        return ans;
    }
};
