class Solution {
private: 
    int solve(vector<vector<int>>& triangle,vector<vector<int>>& dp,int row,int col){
        int m = triangle.size();

        if( row == m - 1){
            return dp[row][col] = triangle[row][col];
        }
        if( row >= m ){
            return INT_MAX;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int currCol = solve(triangle,dp,row + 1,col);
        int nextCol = solve(triangle,dp,row + 1, col + 1);

        return dp[row][col] = min(currCol,nextCol) + triangle[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp;
        for(int i = 0 ; i < m ; i++){
            vector<int> temp;
            for( int j = 0 ; j <= i ; j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }

        solve(triangle,dp,0,0);

        return dp[0][0];
    }
};
