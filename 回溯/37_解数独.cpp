class Solution {
public:
    bool is_Valid(vector<vector<char>> board, int row, int col, char ch){
        for(int i = 0; i < 9; ++i){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3] == ch) return false;
        }
        return true;
    }
        
    bool backtrace(vector<vector<char>>& board, int row, int col){
        //if is finished then return
        if(row == 9) return true;
        //if col is full,then next row
        if(col == 9){
           return backtrace(board, row+1, 0);
        }
        //如果是预先设置的数字，则跳过
        if(board[row][col] != '.'){
            return backtrace(board, row, col+1);
        }
        
        //fill each row
        for(char num = '1'; num <= '9'; ++num){
            if(!is_Valid(board, row, col, num)) continue;    
            board[row][col] = num;
            if(backtrace(board, row, col+1)) return true;
            //remove this step
            board[row][col] = '.';
        }           
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrace(board, 0, 0);
    }
};