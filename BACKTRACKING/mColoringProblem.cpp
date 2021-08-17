//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node, int color[], bool graph[101][101], int col, int N){
    for(int i=0; i<N; i++){
        if(node!=i && graph[node][i]==1 && color[i]==col) return false;
    }
    return true;
}

bool colorgraph(int node, int color[], bool graph[101][101], int m, int N){
    
    if(node==N) return true;
    
    for(int i=1; i<=m; i++){
        if(isSafe(node, color, graph, i, N)){
            color[node]=i;
            if(colorgraph(node+1, color, graph, m, N)) return true;
            color[node]=0; //backtracking step
        }
        
        
    }return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V]={0};
    return colorgraph(0,color, graph, m, V);
    
}