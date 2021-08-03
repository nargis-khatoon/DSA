//given a matrix return the number o fvalid 1. valid 1 = 1 which cannot reach boundary, directly or indirectly
//mark the connected components of the boundary rows and columns. Then count number of 1s
//1020. Number of Enclaves
class Solution {
public:
    
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0) return;
        
        grid[i][j]=0;
        dfs(i+1, j, rows, cols, grid);
        dfs(i-1, j, rows, cols, grid);
        dfs(i, j+1, rows, cols, grid);
        dfs(i, j-1, rows, cols, grid);
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i==0 || j==0 ||i==rows-1 || j==cols-1){
                    if(grid[i][j]==1)
                    dfs(i, j, rows, cols, grid);
                }
            }
        }
        int count=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
        
    }
};
