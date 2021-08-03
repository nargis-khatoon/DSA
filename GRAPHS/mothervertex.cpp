//TO FIND MOTHER VERTEX
//USE KOSARAJU'S ALGO
/*
1)after performing DFS for each component, store the vertex in stack while backtracking. 
2) verify if the top of the stack is a mother vertex
*/

#include <bits/stdc++.h>
using namespace std;

//STEP 1- STORING IN STACK AFTER PERFORMING DFS
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
//STEP 3- PERFORMING DFS
void topDfs(int node, vector<int> &vis, vector<int> adj[], int &count) {
    count++; 
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            topDfs(it, vis, adj, count); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	
	
	// STEP 2-calling dfs with source node as top vertex of stack
    int node = st.top();
    st.pop(); 
    int count=0;
    if(!vis[node]) {
        topDfs(node, vis, adj, count); 
        
    }

    if(count==n) cout<<"mother vertex is" <<node<<"\n";
    else cout<<"-1\n";
	
	
	return 0;
}