//934. Shortest Bridge leetcode-medium
class Solution {
public:
    
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>&grid, vector<vector<int>>& vis, queue<pair<int, int>>& q){
        if(i<0 || j<0 || i>=rows || j>=cols || vis[i][j]==1 || grid [i][j]==0) return;
        int dir[]={0,1, 0, -1, 0};
        for(int k=0; k<4; k++){
            q.push({i,j});
            vis[i][j]=1;
            dfs(i+dir[k], j+dir[k+1], rows, cols, grid, vis, q);
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        
        vector<vector<int>> dirs={{0,1}, {1,0}, {-1, 0}, {0,-1}};
        queue<pair<int, int>> q;
        bool flag=false;
        for(int i=0; i<rows && flag==false; i++){
            for(int j=0; j<cols && flag==false; j++){
                if(grid[i][j]==1) 
                {
                    dfs(i, j, rows, cols, grid, vis, q);
                    flag=true;
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto it=q.front();
                q.pop();
                for(auto dir: dirs){
                    int x=it.first+dir[0], y=it.second+dir[1];
                    if(x<0 || y< 0 || x >=rows || y>=cols || vis[x][y]==1) continue;
                    if(grid[x][y]==1) return level;
                    q.push({x,y});
                    vis[x][y]=1;
                    
                }
            }
            level++;
            
        }
        return -1;
    }
};