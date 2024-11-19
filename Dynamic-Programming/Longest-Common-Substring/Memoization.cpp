//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solve(int index1, int index2,string s1, string s2,int ansTillNow,vector<vector<vector<int>>> & dp){
        if(index1 >= s1.size() || index2 >= s2.size()){
            return ansTillNow;
        }
        
        if(dp[index1][index2][ansTillNow] != -1){
            return dp[index1][index2][ansTillNow];
        }
        int ans = 0;
        if(s1[index1 ] == s2[index2 ]){
            ans = solve(index1 + 1,index2 + 1,s1,s2,ansTillNow + 1,dp)  ;
        }
        int ans1 = solve(index1 + 1,index2,s1,s2,0,dp);
        int ans2 = solve(index1,index2 + 1,s1,s2,0,dp);
        return dp[index1][index2][ansTillNow] = max(ans,max(ans1,max(ansTillNow,ans2)));
    }
  public:
    int longestCommonSubstr(string s1, string s2) {
        vector<vector<vector<int>>> dp(s1.size() ,vector<vector<int>>(s2.size(),vector<int>(min(s1.size(),s2.size()),-1)));
        return solve(0,0,s1,s2,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
