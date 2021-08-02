#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool dfsCycle(int node, vector<int> adj[], vector<int> vis, vector<int> dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCycle(it, adj, vis, dfsVis)) return true;
            }if(dfsVis[it]) return true;
        }
        dfsVis[node]=0;
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]){
        vector<int> vis(V-1, 0);
        vector<int> dfsVis(V-1, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfsCycle(i, adj, vis, dfsVis)) return true;
            }
        }
        return false;
    }

};



int main(){
    int tc;
    while(tc--){
        int V, E;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i=0; i<E; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        Solution obj;
    	cout << obj.detectCycle(V, adj) << "\n";

    }
    return 0;
}