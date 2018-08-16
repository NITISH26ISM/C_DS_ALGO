# include <iostream>
# include <vector>
using namespace std;

void addEdge( vector<int> adj[], int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void printGraph( vector<int> adj[], int V){
    for( int i = 0; i < V; i++ ){
        cout<<"Adjacency List of "<<i<<endl;
        for( int j = 0; j < V; j++ ){
            if(adj[i][j] == 1 ){
                cout<<j<<"->";
            }
        }
        cout<<"null\n";
    }
}

int main(){
    int V = 5;
    
    vector<int> adj[V];
    for( int i = 0; i < V; i++ ){
        adj[i].resize(V);
        fill( adj[i].begin(), adj[i].end(), 0 );
    }
        
    addEdge( adj, 0, 1 );
    addEdge( adj, 0, 4 );
    addEdge( adj, 1, 2 );
    addEdge( adj, 1, 3 );
    addEdge( adj, 1, 4 );
    addEdge( adj, 2, 3 );
    addEdge( adj, 3, 4 );
    
    printGraph( adj, V );
}
