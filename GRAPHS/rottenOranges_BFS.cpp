class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1, -1, 0, 0};
        int dy[]={0,0, 1, -1};
        queue<pair<int, int>> q;
        int countof1=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    countof1++;
                    
            }
        }
        if(countof1==0) return 0; //because all oranges are already rotten
        
        int t=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int, int> rem=q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int x=rem.first+dx[i];
                    int y=rem.second+dy[i];
                    
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                        countof1--;
                    }
                }  
            }
            if(!q.empty()) t++;
        }
        if(countof1!=0) return -1;
        return t;
        
        
    }
};