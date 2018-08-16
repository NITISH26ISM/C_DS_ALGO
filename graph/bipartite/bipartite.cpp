# include <iostream>
# include <list>
# include <cstring>
# include <queue>

using namespace std;

void addEdge(list<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBipartite( list<int> adj[], int V ){
    int visited[V];
    int level[V];
    
    memset(visited, 0, V*sizeof(int) );
    memset(level, -1, V*sizeof(int) );
    
    queue<int> q;
    
    int s = 0;
    visited[s] = 1;
    level[s] = 0;
    q.push(s);
    
    while(!q.empty() ){
        s = q.front();
        q.pop();
        for( auto itr = adj[s].begin(); itr != adj[s].end(); itr++ ){
            if( !visited[*itr] ){
                visited[*itr] = 1;
                level[*itr] = level[s] + 1;
                q.push(*itr);
            }
            else if( level[*itr] == level[s]){
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    int v = 8;
    list<int> adj[v];
    
    addEdge(adj, 0,1 );
    addEdge(adj, 1, 2);
    addEdge(adj, 2,3 );
    addEdge(adj, 3,4 );
    addEdge(adj, 4,5 );
    addEdge(adj, 5,6 );
    addEdge(adj, 6,7 );
    addEdge(adj, 7,0 );
    //addEdge(adj, 5,5 );
    
    (isBipartite(adj, v))? cout<<"Yes\n": cout<<"No\n";
    
    return 0;
}
