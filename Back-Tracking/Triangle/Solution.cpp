class Solution {
private:
    int solve(vector<vector<int>>& triangle,int row,int col){
        int noOfRows = triangle.size();

        if(row == noOfRows - 1){
            return triangle[row][col];
        }
        if( row >= noOfRows){
            return INT_MAX;
        }
 
        int currCol = solve(triangle,row + 1,col);
        int nextCol = solve(triangle,row + 1,col + 1);

        return min(currCol,nextCol) + triangle[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int noOfRows = triangle.size();

        return solve(triangle,0,0);
    }
};
