# include <iostream>
# include <list>
# include <queue>
# include <cstring>

using namespace std;

void addEdge(list<int> adj[], int u, int v ){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(list<int> adj[], int s, int visited[], int a[], int b[], int& time ){
    visited[s] = 1; a[s] = time++;
    cout<<s<<" ";
    for( auto itr = adj[s].begin(); itr != adj[s].end(); itr++ ){
        if( !visited[*itr] ){
            dfs(adj, *itr, visited, a,b, time);
        }
    }
    b[s] = time++;
}

int main()
{
    int v = 8;
    list<int> adj[v];
    
    int visited[v], a[v], b[v];
    memset(visited, 0, v*sizeof(int));
    memset(a, 0, v*sizeof(int));
    memset(b, 0, v*sizeof(int));
    
    addEdge( adj, 0, 1 );
    addEdge( adj, 0, 2);
    addEdge( adj, 0, 3);
    addEdge( adj, 1, 4 );
    addEdge( adj,  4, 5 );
    addEdge( adj,  4, 3 );
    addEdge( adj,  2, 6 );
    addEdge( adj,  2, 7 );
    addEdge( adj,  6, 7 );
    int time = 0;
    dfs( adj, 0 , visited, a, b, time);
    cout<<endl;
    
    
    for( int i = 0; i < v; i++){
        cout<<"vertex : "<<i<<" arrival: "<<a[i]<<" dep: "<<b[i]<<endl;
    }
    
    
    
}

