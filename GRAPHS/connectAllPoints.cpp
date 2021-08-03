//PRIMS ALGO
//1584. Min Cost to Connect All Points-Leetcode (Medium)
class Solution {
public:
int minCostConnectPoints(vector<vector<int>> &points) {

    int graph[1001][1001];
    
    for(int i=0;i<points.size();i++)
    {
        for(int j=0;j<points.size();j++)
        {
            
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[j][0];
            int y2=points[j][1];
            
            int dist=abs(x1-x2)+abs(y1-y2);
            graph[i][j]=dist;
        }
    }
    
 
    
    // key array will give the minimum 
    int key[1001];

    bool mset[1001]={false};
    long long res=0;
    for(int i=0;i<=1000;i++)
        key[i]=INT_MAX;
    key[0]=0;
    for(int i=0;i<points.size();i++)
    {
        
        // select minimum from key array
        int u=1000;
        for(int j=0;j<points.size();j++)
        {
            if(!mset[j] && (u==1000||key[j]<key[u]))
                u=j;
                
        }
        
        
        mset[u]=true;
        res+=key[u];
        
        //Now update all the edges which are adjacent to the given points.
        for(int adj=0;adj<points.size();adj++)
        {
            if(graph[u][adj]!=0 && !mset[adj])
            {
                
             key[adj]=min(key[adj],graph[u][adj]);
                                  
            }
            
        }
    }
    
    return res;
    
    }
};