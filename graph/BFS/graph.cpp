# include <iostream>
# include <list>
# include <queue>
# include <cstring>

using namespace std;

class Graph{
private:
    int V;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge( int v, int u );
    void BFS( int s );
};

Graph::Graph( int v){
    V = v;
    adj = new list<int>[v];
}

void Graph::addEdge( int v, int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    int visited[V+1];
    memset(visited, 0, V*sizeof(int));
    queue<int> q;
    
    visited[s] = 1;
    q.push(s);
    
    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for( auto itr = adj[s].begin(); itr != adj[s].end(); itr++ ){
            if( visited[*itr] == 0 ){
                visited[*itr] = 1;
                q.push(*itr);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);
    
    return 0;
}
