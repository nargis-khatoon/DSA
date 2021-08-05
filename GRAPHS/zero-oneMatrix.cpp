class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size(), cols=mat[0].size();
        vector<vector<int>> dirs={{0,-1}, {0,1}, {1,0}, {-1, 0}};
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]==0) q.push({i, j});
                else mat[i][j]=INT_MAX;
            }
        }
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            for(auto d:dirs){
                int x=it.first+d[0], y=it.second+d[1];
                if(x<0 || y<0 ||x>=rows ||y >=cols || mat[x][y]<=mat[it.first][it.second]+1) continue;
                mat[x][y]=mat[it.first][it.second]+1;
                q.push({x,y});
            }
        }
        return mat;
        
    }
};