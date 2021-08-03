/*Instead of creating the min heap as mentioned in the video , we can create a
max heap instead and then push negative weights in the priority queue and then 
while taking out the node from the priority queue we can use abs value instead
*/

int main(){
    int n,e;    cin >> n >> e;
    vector<vector<pair<int , int>>>g(n);
    int u , v, w;
    for(int i=0; i<e; i++){
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    priority_queue<pair<int , int>>pq;
    int src;    cin >> src;
    vector<int>dist(n , 1e9);
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(auto it : g[node.second]){
            if(abs(node.first) + it.second < dist[it.first]){
                dist[it.first] = abs(node.first)+it.second;
                pq.push({-dist[it.first] , it.first});
            }
        }
    }

