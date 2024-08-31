class Solution {
    bool isPalindrome( string s){
        if( s.size() == 1){
            return true;
        }

        for( int i = 0 ; i < s.size() / 2 ;i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    void getAllPalindromicPartitions(vector<vector<string>> & ans,vector<string> temp,string &s,int pos){
        if( pos >= s.size()){
            ans.push_back(temp);
            return;
        }

        string tempString ="";

        for( int i = pos ; i < s.size() ; i++){
            tempString += s[i];
            if( isPalindrome(tempString)){
                temp.push_back(tempString);
                getAllPalindromicPartitions(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        getAllPalindromicPartitions(ans,{},s,0);
        return ans;
    }
};
