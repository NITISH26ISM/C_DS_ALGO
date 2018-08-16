# include <iostream>
# include <list>
# include <cstring>

using namespace std;

void addEdge(list<int> adj[], int u, int v){
    adj[u].push_back(v);
}

bool isAcylic( list<int> adj[], int src, int visited[], int a[], int d[], int& time ){
    visited[ src ] = 1;
    a[src] = time++;
    for( auto itr = adj[src].begin(); itr != adj[src].end(); itr++ ){
        if( !visited[*itr] ){
            if( !isAcylic(adj, *itr, visited, a, d, time) ){
                return false;
            }
        }
        else if( a[*itr] < a[src] && d[*itr] == -1 ){
            return false;
        }
    }
    d[src] = time++;
    return true;
}

int main(){
    int v = 7;
    list<int> adj[v];
    
    addEdge(adj, 0,1 );
    addEdge(adj, 0,2 );
    addEdge(adj, 1,3 );
    addEdge(adj, 1,4 );
    addEdge(adj, 3,5 );
    addEdge(adj, 4,5 );
    addEdge(adj, 2,6 );
    addEdge(adj, 6,4 );
    addEdge(adj, 6,5 );
    addEdge(adj, 1,2 );
   // addEdge(adj, 4,1 );
    
    int visited[v];
    int a[v];
    int d[v];
    memset( visited, 0, v*sizeof(int) );
    memset( a, -1, v*sizeof(int) );
    memset( d, -1, v*sizeof(int) );
    int time = 0;
    int i = 0;
    bool state = true;
    while( state && i < v ){
    state =  isAcylic( adj, i,visited, a, d, time ) ;
    
        while( i < v && visited[i] == 1){
            i++;
        }
    }
    
    (state)?cout<<"yes\n":cout<<"no\n";
    

    return 0;
}

