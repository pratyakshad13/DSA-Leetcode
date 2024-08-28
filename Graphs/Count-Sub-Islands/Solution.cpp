class Solution {
private:
    bool isValid(int row,int col, vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();

        if( row >= m || row < 0 || col >= n || col < 0){
            return false;
        }
        return true;
    }

    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& visited,int row,int col){
        visited[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        bool isAsubIsland = true;

        if( grid1[row][col] == 0){
            isAsubIsland = false;
        }

        bool ans = true;
        for( int i = 0 ; i < 4 ; i++){
            int currRow = delRow[i] + row;
            int currCol = delCol[i] + col;
            if( isValid(currRow,currCol,grid2) && !visited[currRow][currCol] && grid2[currRow][currCol] == 1){
                ans = isSubIsland(grid1,grid2,visited,currRow,currCol);
                if(!ans && isAsubIsland){
                    isAsubIsland = false;;
                }
            }
        }
        return isAsubIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        int count = 0;

        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if( !visited[i][j] && grid2[i][j] == 1){
                    bool ans = isSubIsland(grid1,grid2,visited,i,j);
                    if( ans){
                        count++;
                    }
                }
            }
        }
        return count;

    }
};
