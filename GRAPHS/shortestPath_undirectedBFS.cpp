//UNDIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> shortestPath(int src, int V, vector<int> adj[]){
        vector <int> dist(V, INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
}