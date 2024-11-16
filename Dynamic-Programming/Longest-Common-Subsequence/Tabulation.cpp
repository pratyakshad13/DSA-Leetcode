class Solution {
private:
    int solve(int index1,int index2,string s1,string s2,vector<vector<int>> &dp){
        if( index1 >= s1.size() || index2 >= s2.size()){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int ans1 = 0,ans2 = 0, ans3 = 0;
        if( s1[index1] == s2[index2]){
            ans1 = solve(index1 + 1,index2 + 1,s1, s2,dp) + 1;
        }

        ans2 = solve(index1 + 1,index2,s1, s2 ,dp);
        ans3 = solve(index1 ,index2 + 1,s1, s2 ,dp);

        return dp[index1][index2] = max(ans1,max(ans2,ans3));

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,vector<int>(text2.size() + 1,0));

        if( text1.size()==0 || text2.size() == 0){
            return 0;
        }
        
        // dp[0][0] = 1;
        for( int length1 = 1; length1 <text1.size() ; length1++){
            dp[length1][0] = 0;
        }

        for( int length2 = 1; length2 <text2.size() ; length2++){
            dp[0][length2] = 0;
        }

        for( int length1 = 1; length1 <= text1.size() ; length1++){
            for( int length2 = 1; length2 <= text2.size() ;length2++){
                int ans1 = 0 , ans2 , ans3 ;
                if( text1[length1 - 1] == text2[length2 - 1]){
                    dp[length1 ][length2] = dp[length1 - 1][length2 - 1]  + 1;
                }
                else{
                    ans2 = dp[length1 - 1][length2];
                    ans3 = dp[length1][length2 - 1];

                    dp[length1 ][length2] = max(ans2,ans3);
                }

            }
        }

        return dp[text1.size() ][text2.size() ];
        
    }
};
