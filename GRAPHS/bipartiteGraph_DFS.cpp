#include<bits/stdc++.h>
using namespace std;

 // 0 based indexed graph code


class Solution {

public:
    bool dfsColor(int node, vector<int> &color, vector<int> adj[]) {
        if(color[node]==-1) color[node]=1;
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!dfsColor(it, color, adj)) return false;
            }else if(color[it]==color[node]) return false;
        }
        return true;

    }

    bool isBipartite(int V, vector<int> adj[]){
        vector<int> color(V, -1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(dfsColor(i, color, adj)==false) return false;
            }
        }
        return true;
    }
};

        
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if(ans)
			cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends