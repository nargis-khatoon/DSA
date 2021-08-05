//count number of distinct islands
//leetfree distinct island
//INTUITION 
/*
When we start a depth-first search on the top-left square of some island, 
the path taken by our depth-first search will be the same if and only if the
shape is the same. We can exploit this by recording the path we take as our 
shape - keeping in mind to record both when we enter and when we exit the function
*/
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<vector<int>>> distinctIslands;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                vector<vector<int>> island;
                if (dfs(i, j, i, j, grid, m, n, island)){
                    distinctIslands.insert(island);
                }
            }
        }
        return distinctIslands.size();
    }
private:
    int d [5]  = {0,1,0,-1,0};

    bool dfs(int i, int j, int x, int y, vector<vector<int>> & grid, int m, int n, vector<vector<int>> & island){
        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] <= 0) return false;
        grid[x][y] *= -1;
        island.emplace_back(x-i, y-j);
        for(int k = 0; k < 4; k++){
            dfs(i, j, x + d[k], y + d[k + 1], grid, m, n, island);
        }

        return true;
    }

};