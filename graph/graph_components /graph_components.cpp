# include <iostream>
# include <list>
# include <cstring>
# include <queue>

using namespace std;

void addEdge( list<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(list<int> adj[], int v, int s, int comp_no[], int count ){
    int visited[v];
    memset(visited, 0, v*sizeof(int));
    
    queue<int> q;
    visited[s] = 1;
    comp_no[s] = count;
    q.push(s);
    
    while(!q.empty()){
        s = q.front();
        q.pop();
        for( auto itr = adj[s].begin(); itr != adj[s].end(); itr++ ){
            if( !visited[*itr] ){
                visited[*itr] = 1;
                comp_no[*itr] = count;
                q.push(*itr);
            }
        }
    }
    
}

int partition_comp(list<int> adj[], int v, int comp_no[]){
    int i = 0, count = 1;
    while( i != v ){
        while( i < v && comp_no[i] != 0 )
            i++;
        
        if( i >= v )
            break;
        
        bfs( adj, v, i, comp_no, count);
        count++;
    }
    
    return count-1;
}

int main(){
    int v = 14;
    list<int> adj[v];
    
    addEdge(adj,1 ,2);
    addEdge(adj, 2,3);
    addEdge(adj, 1,3);
    addEdge(adj, 4,7);
    addEdge(adj, 5,7);
    addEdge(adj, 6,7);
    addEdge(adj, 8,11);
    addEdge(adj, 11,10);
    addEdge(adj, 8,9);
    addEdge(adj, 9,10);
    addEdge(adj, 11,9);
    addEdge(adj, 8,10);
    
    int comp_no[v];
    memset(comp_no, 0, (v)*sizeof(int) );
    int n = partition_comp( adj, v, comp_no );
    cout<<"no of components: "<<n<<endl;
    
    for( int i = 1; i <= n; i++ ){
        cout<<"components no "<<i<<" :";
        for( int j = 0 ; j < v; j++ ){
            if( comp_no[j] == i){
                cout<<j<<", ";
            }
        }
        cout<<endl;
    }
    
    return 0;
    
}
