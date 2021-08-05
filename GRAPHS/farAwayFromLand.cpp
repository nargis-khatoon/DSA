//SAME AS 01 MATRIX
//COUNTING LEVELS 
//1162. As Far from Land as Possible leetcode Medium
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        queue<pair<int, int>> q;
        
        vector<vector<int>> dirs={{0,1},{1,0}, {0, -1}, {-1, 0} };
        for(int i= 0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1) q.push({i, j});
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto it= q.front();
                q.pop();
                for(auto dir: dirs){
                    int x=it.first+dir[0], y=it.second+dir[1];
                    if(x<0 || y<0 || x>=rows || y>=cols || grid[x][y]==1) continue;
                    grid[x][y]=1;
                    q.push({x,y});
                
                }
                       
                       
            }
            if(!q.empty()) level++;
            
            
            
        }
        if(level!=0)
        return level;
        else return -1;
        
    }
};