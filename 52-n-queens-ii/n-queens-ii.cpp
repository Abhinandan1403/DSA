class Solution {
public:
    int totalNQueens(int n) {
        string s = "";
        for(int i = 0 ; i<n ; i++){
            s.push_back('.');
        }
        vector<string>board(n);
        for(int i = 0 ; i<n ; i++){
            board.push_back(s);
        }

        return solve(board, 0, n);
    }

    int solve(vector<string>& board, int col, int n){
        if(col == n){
            return 1 ;
        }
        int ans = 0 ;

        for(int row = 0 ; row<n ; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                ans += solve(board, col+1, n);
                board[row][col] = '.';
            }
        }

        return ans ;
    }

    bool isSafe(int row, int col, vector<string>& board){
        int r = row , c = col , n = board.size() ;
        while(row-1>=0 && col-1>=0){
            row--;
            col--;
            if(board[row][col] == 'Q'){
                return false;
            }
        }

        row = r, col = c;
        while(row+1<n && col-1>=0){
            row++;
            col--;
            if(board[row][col] == 'Q'){
                return false;
            }
        }
        row = r, col = c ;
        while(col-1>=0){
            col--;
            if(board[row][col] == 'Q'){
                return false ;
            }
        }

        return true;
    }
};