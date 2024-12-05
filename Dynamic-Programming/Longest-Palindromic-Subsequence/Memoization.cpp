class Solution {
private:
    int solve(int pos1,int pos2,string &s,vector<vector<int>> & dp){
        if( pos2 < pos1){
            return 0;
        }
        if( pos2 == pos1){
            return 1;
        }

        if( dp[pos1][pos2] != -1){
            return dp[pos1][pos2];
        }

        int ans1 = 0;
        int ans2,ans3;
        if(s[pos1] == s[pos2]){
            ans1 = 2 + solve(pos1 + 1,pos2 - 1,s,dp);
        }
        ans2 = solve(pos1,pos2 - 1,s,dp);
        ans3 = solve(pos1 + 1,pos2 ,s,dp);

        return dp[pos1][pos2] = max(ans1,max(ans2,ans3));

    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size() + 1,vector<int>(s.size() + 1,-1));
        return solve(0,s.size() - 1,s,dp);
    }
};
