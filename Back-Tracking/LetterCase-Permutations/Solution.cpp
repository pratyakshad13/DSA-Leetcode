class Solution {
private:
    void getAllLetterCasePermutations(string s, vector<string> & ans, string temp, int pos){

        if( pos >= s.size() ){
            ans.push_back(temp);
            return;
        }

        int currChar = s[pos];
        if(currChar >=65 && currChar <=90){
            temp = temp + (char)(currChar + 32);
            getAllLetterCasePermutations(s,ans,temp,pos + 1);
            temp.pop_back();
        }
        if(currChar >=97){
            temp = temp + (char)(currChar - 32);
            getAllLetterCasePermutations(s,ans,temp,pos + 1);
            temp.pop_back();
        }
        temp += s[pos];
        getAllLetterCasePermutations(s,ans,temp,pos + 1);

    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        getAllLetterCasePermutations(s,ans,"",0);
        return ans;
    }
};
