# include <iostream>
# include <cstring>
# include <list>
# include<climits>

using namespace std;

void addEdge( list<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool two_edge_con( list<int> adj[], int src, int v, int visited[], int a[], int& time, int& min  ){
    visited[src] = 1; a[src] = time++;
    cout<<src<<" ";
    int deep = time;
    for( auto itr = adj[src].begin(); itr != adj[src].end(); itr++ ){
        if( !visited[*itr] ){
            if(two_edge_con(adj, *itr, v, visited, a, time, deep)){
                if( min > deep ){
                    min = deep;
                }
            }
            else{
                return false;
            }
        }
        else{
            if( a[src]-1 != a[*itr] &&  min > a[*itr] ){
                min = a[*itr];
            }
        }
    }
    cout<<endl;
    cout<<"src "<<src<<"  "<<"it's deep "<<min<<endl;
    if( src == 0){
        return true;
    }
    
    if( a[src] > min ){
        return true;
    }
    else{
        return false;
    }
    
}

int main(){
    int v = 5;
    list<int> adj[v];
    
    addEdge( adj, 0,2 );
    addEdge( adj, 0,1 );
    addEdge( adj, 1,2 );
    //addEdge( adj, 1,3 );
    addEdge( adj, 1,4 );
    addEdge( adj, 2,3 );
   // addEdge( adj, 2,4 );
    //addEdge( adj, 4,3 );
    //addEdge( adj, 8,9 );
   // addEdge( adj, 9,0 );
    
    int visited[v];
    int a[v];
    memset( visited, 0, v*sizeof(int) );
    memset( a, -1, v*sizeof(int) );
    int time = 0;
    int min = INT_MAX;
    (two_edge_con(adj, 0, v, visited, a, time, min ))?cout<<"yes":cout<<"no";
    cout<<endl;
    
    return 0;
}
