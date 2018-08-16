# include <iostream>
# include <vector>
# include <cstring>
# include <algorithm>

using namespace std;





struct set{
    int parent;
    int rank;
};

class Edge{
public:
    int src;
    int dest;
    int weight;
    Edge() { }
    
    Edge( int s, int d, int w){
        src = s;
        dest = d;
        weight = w;
    }
};



class Graph{
public:
    int V,E;
    vector<Edge> edge;
    
    Graph(int v, int e){
        V = v;
        E = e;
        edge.resize(E);
    }
    
    void addEdge( int s, int d, int w){
        edge.push_back(Edge(s,d,w));
    }

};

int Find( vector<set>& subset, int k ){
    while( k != subset[k].parent ){
        k = subset[k].parent;
    }
    
    return k;
}

void Union( vector<set> &subset, int a, int b){
    int x = Find(subset, a);
    int y = Find(subset, b);
    
    if( subset[x].rank < subset[y].rank ){
        subset[x].parent = y;
        subset[y].rank += subset[x].rank; 
    }
    else{
        subset[y].parent = x;
        subset[x].rank += subset[y].rank;
    }
}

bool cmp( Edge a, Edge b ){
    if( a.weight < b.weight )
        return true;
    return false;
}

void KruskalMST( Graph g ){
    vector<Edge> mst;
    vector<set> subset;
    subset.resize(g.V);
    
    for( int i = 0; i < g.V; i++ ){
        subset[i].parent = i;
        subset[i].rank = 1;
    }
    
    sort( g.edge.begin(), g.edge.end(), cmp );
    
    for( auto e = g.edge.begin(); mst.size() != g.V - 1  && e != g.edge.end(); e++ ){
        int u = e->src;
        int v = e->dest;
        
        int r_u = Find( subset, u );
        int r_v = Find( subset, v );
        
        if( r_u != r_v ){
            mst.push_back(*e);
            Union( subset, r_u, r_v );
        }
    }
    
    for( auto e = mst.begin(); e != mst.end(); e++ ){
        cout<<e->src<<"------"<<e->dest<<" wt: "<<e->weight<<endl;
    }
    
}



int main(){
    int v = 4;
    int e = 5;
    
    Graph g(4,5);
    
    g.addEdge( 0, 1 ,10  );
    g.addEdge( 0, 2 , 6  );
    g.addEdge( 0, 3 , 5  );
    g.addEdge( 1, 3 , 15 );
    g.addEdge( 2, 3 , 4 );
    
    KruskalMST(g);
    
    return 0;
}
