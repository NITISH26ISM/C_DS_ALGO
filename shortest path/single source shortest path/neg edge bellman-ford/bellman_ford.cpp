//complexity O(mn)

# include <iostream>
# include <list>
# include <vector>
# include <climits>
# include <cstring>

using namespace std;

struct edge{
    int vertex;
    int wt;
    edge() { }
    
    edge( int v, int w ){
        vertex = v;
        wt = w;
    }
};

void addEdge( list<edge> adj[], int u, int v, int wt ){
    adj[u].push_back( edge( v, wt) );
}

int bellman_ford( list<edge> adj[], int v ){
    int dist[v];
    
    for( int i = 0 ; i < v; i++ ){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for( int i = 0; i < v-1; i++ ){
        for( int j = 0; j < v; j++ ){ //cout<<"for i = "<<i<<endl;
            for( auto itr = adj[j].begin(); itr != adj[j].end(); itr++ ){
                
                if( dist[j] != INT_MAX && dist[(*itr).vertex] > dist[j] + (*itr).wt  ){
                    dist[(*itr).vertex] = dist[j] + (*itr).wt;
                }
            }
            
        }
    }
    int flag = 1;
    for( int i = 0; i < v; i++ ){
        for( auto it = adj[i].begin(); it != adj[i].end(); it++ ){
            if( dist[(*it).vertex] > dist[i] + (*it).wt  ){
                return -1;
            }
        }
    } 


    cout<<"vertex\tdistane from source\n";
    for( int i = 0 ; i< v; i++ ){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
    return 1;
}

int main(){
    int v = 5;
    list<edge> adj[v];
    
    addEdge( adj,  0,  1, -1);
    addEdge( adj,  0,  2, 4 );
    addEdge( adj,  1,  2, 3 );
    addEdge( adj,  3,  1, 1 );
    addEdge( adj,  1,  3, 2 );
    addEdge( adj,  1,  4, 2 );
    addEdge( adj,  4,  3, -3);
    addEdge( adj,  3,  2, 5 );
    addEdge( adj,  3,  0, 1 );
    
    int flag = bellman_ford( adj, v );
    if(flag == -1 )
        cout<<"Cycle detected!!!!\n";
    
    return 0;
}
