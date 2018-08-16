# include <iostream>
# include <list>
# include <queue>
# include <cstring>
# include <stack>

using namespace std;

void addEdge(list<int> adj[], int u, int v ){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(list<int> adj[], int src , int v){
    int visited[v];
    memset(visited, 0, v*sizeof(int));

    stack<int> s;
    stack<list<int>::iterator > i;
    auto itr = adj[src].begin();
    
    s.push(src);
    i.push(itr);
    visited[src] = 1;
    cout<<src<<" ";
    while( !s.empty() ){
        src = s.top();
        itr = i.top();
        
        while(visited[*itr]){
            itr++;

            if( itr == adj[src].end() ){
                s.pop();
                i.pop();
                if( s.empty() )
                    return ;
                src = s.top();
                itr = i.top();
            }
        }

        visited[*itr] = 1;
        cout<<*itr<<" ";
        s.push(*itr);
        auto it = adj[(*itr)].begin();
        i.push(it);
        
    }

}

int main()
{
    int v = 8;
    list<int> adj[v];
    
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
    dfs( adj, 0,v);
    cout<<endl;
    
    
}

