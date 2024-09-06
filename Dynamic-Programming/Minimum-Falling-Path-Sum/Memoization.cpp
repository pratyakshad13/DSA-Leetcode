class Solution {
private:
    bool isValid(int row ,int col ,vector<vector<int>> & matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        if( col >= n || col < 0 ){
            return false;
        }

        return true;
    }
    int solve(vector<vector<int>>& matrix,map<pair<int,int>,int> & mp,int row,int col){
        if(  !isValid(row,col,matrix)){
            return INT_MAX;
        }
        if( row == 0 && isValid(row,col,matrix)){
            return mp[{row,col}] = matrix[row][col];
        }

        if(mp.count({row,col}) > 0){
            return mp[{row,col}];
        }

        int up = INT_MAX,left = INT_MAX,right = INT_MAX;
        
            up= solve(matrix,mp,row - 1,col) ;
        
            left = solve(matrix,mp,row - 1,col - 1);
        
            right = solve(matrix,mp,row - 1,col + 1);
        int ans = min(up,min(left,right));
        if( ans != INT_MAX){
            return mp[{row,col}] = ans + + matrix[row][col];
        } 
        return mp[{row,col}] = matrix[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<pair<int,int>,int> mp;

        int ans = INT_MAX;
        
        for( int col = 0 ; col < n ; col ++){
            ans = min(ans,solve(matrix,mp,m-1,col));
        }
        return ans;
    }
};
