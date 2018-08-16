# include <iostream>
# include <vector>
# include <queue>

using namespace std;

void addEdge( vector<int> adj[], int u, int v ){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs( vector<int> adj[], int s, int V ){
    int color[V];
    int pi[V];
    int label[V];
    for( int i = 0; i < V; i++){
        color[i] = -1;
        pi[i] = -1;
        label[i] = -1;
    }
    
    queue<int> q;
    q.push(s);
    color[s] = 0;
    label[s] = 0;
    
    while(!q.empty()){
        int top = q.front();
        cout<<top<<" ";
        for( auto itr = adj[top].begin(); itr != adj[top].end(); itr++ ){
            if( color[*itr] == -1 ){
                color[*itr] = 0;
                label[*itr] = label[top] + 1;
                pi[*itr] = top;
                q.push(*itr);
            }
        }
        color[top] = 1;
        q.pop();
    }
        cout<<endl;
}

int main(){
    int V = 4;
    vector<int> adj[V];
    
    addEdge(adj, 0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    //addEdge(adj, 3, 3);
    
    bfs( adj, 2 , V);
}
