class Solution {
private:
    bool isValid( int row,int col ,char num, vector<vector<char>>& board){
        for( int r = 0 ; r < 9 ; r++ ){
            if(board[r][col] == num){
                return false;
            }
        }
        for( int c = 0 ; c < 9 ; c++ ){
            if(board[row][c] == num){
                return false;
            }
        }

        int newRow = row - (row%3);
        int newCol = col - (col%3);
        for( int i = newRow ; i < newRow + 3 ; i++){
            for( int j = newCol ; j <newCol + 3 ; j++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board,int row,int col){
        if( row == 9){
            return true;
        }
        if( col == 9){
            return solveSudoku(board,row+1,0);
        }
        
            if( board[row][col] =='.'){
                for( char num = 49 ; num < 58 ; num++){
                    
                    if(isValid(row,col,num,board)){
                        board[row][col] = num;
                        bool ans = solveSudoku( board,row,col + 1);
                        if( ans ){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
            }
            else{
                return solveSudoku( board,row,col + 1);
            }
            
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board,0,0);
        return;
    }
};
