// count no. of shapes 
// count number of islands

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
     void mark_shapes(int i, int j, int rows, int cols, vector<vector<char>>&grid){
        if(i<0 || i>=rows ||j<0 ||j>=cols || grid[i][j]!='X')
        return ;
        grid[i][j]='2';
        mark_shapes(i+1, j, rows, cols, grid);
        mark_shapes(i, j+1, rows, cols, grid);
        mark_shapes(i-1, j, rows, cols, grid);
        mark_shapes(i, j-1, rows, cols, grid);
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int rows=grid.size();
        if(rows==0) return 0;
        int cols=grid[0].size();
        if(cols==1 && rows==1){
            if(grid[0][0]=='X') return 1;
            else return 0;
        }
        int count=0;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='X'){
                    mark_shapes(i, j, rows, cols, grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends

