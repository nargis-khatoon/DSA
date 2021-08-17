/*
    Time complexity: O(N!)
    Unlike the brute force approach, we will only place queens on squares that aren't under attack.
    For the first queen, we have N options. For the next queen, we won't attempt to place it in the
    same column as the first queen, and there must be at least one square attacked diagonally by the
    first queen as well. Thus, the maximum number of squares we can consider for the second queen is
    (N−2). For the third queen, we won't attempt to place it in 2 columns already occupied by the first
    2 queens, and there must be at least two squares attacked diagonally from the first 2 queens.
    Thus, the maximum number of squares we can consider for the third queen is (N-4).
    This pattern continues, resulting in an approximate time complexity of O(N!)
*/

class Solution {
public:
    vector<vector<string>> ans;
    
    bool isValid(int row, int col, vector<string> &board){
        
        //upper col
        for(int i=row; i>=0; i--){
            if(board[i][col]=='Q')
            return false;
        }
        //upper right diagonal
        for(int i=row, j=col; i>=0 && j<board.size(); i--, j++){
            if(board[i][j]=='Q')
            return false;
        }
        //upper left diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q')
            return false;
        }
        return true;
        
    }
    
    void dfs(int row, vector<string> &board){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int i=0; i<board.size(); i++){
            if(isValid(row, i, board)){
                board[row][i]='Q';
                dfs(row+1, board);
                board[row][i]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
        vector<string> board(n, string(n, '.'));
        dfs(0, board);
        return ans;
    }
};