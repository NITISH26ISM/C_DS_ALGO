# include <iostream>
# include <list>
# include <cstring>
# include <climits>

using namespace std;

void addEdge( list<int> adj[], int u, int v ){
    adj[u].push_back(v);
}

bool strongly_conn( list<int> adj[], int visited[], int src , int a[], int& time, int& min ){
    visited[src] = 1;
    a[src] = time++;
    min = a[src];
    int deep = a[src];
   // cout<<src<<" ";
    for( auto itr = adj[src].begin(); itr != adj[src].end(); itr++ ){
        if( !visited[*itr] ){
            if( !strongly_conn(adj, visited, *itr, a, time, deep)){
                return false;
            }
           
            if( min > deep ){
                min = deep;
            }
        }
        else if( a[*itr] < min ){
            min = a[*itr];
        }
    }
    //cout<<endl;
    //cout<<"min"<<min<<" "<<src<<endl;
    
    time++;
    if( src == 0 ){
        return true;
    }
    
    if( min < a[src] ){
        return true;
    }
    else
        return false;
}

int main(){
    int v = 6;
    list<int> adj[v];
    
    addEdge(adj, 0,2 );
    addEdge(adj, 2,3 );
    addEdge(adj, 3,1 );
    addEdge(adj, 1,0 );
    addEdge(adj, 3,5 );
    addEdge(adj, 5,4 );
    addEdge(adj, 4,2 );
    //addEdge(adj, , );
    
    int visited[v];
    memset(visited, 0, v*sizeof(int) );
    int a[v];
    memset(a, -1, v*sizeof(int));
    int time = 0;
    int min = INT_MAX;
    (strongly_conn( adj, visited, 0,a, time, min ))?cout<<"Yes\n":cout<<"No\n";
    
    return 0;
}

