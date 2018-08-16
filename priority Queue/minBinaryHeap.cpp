# include <iostream>
# include <vector>
# include <unordered_map>
# include <cstring>
# include <list>
# include <climits>

using namespace std;

struct node{
    int vertice;
    int priority;
    
    node() { }
    
    node(int v, int p){
        vertice = v;
        priority = p;
    }
};

struct edge{
    int v;
    int wt;
    
    edge( ) { }
    
    edge( int vr, int w ){
        v = vr;
        wt = w;
    }
};

void addEdge( list<edge> adj[], int u, int v, int w){
    adj[u].push_back(edge(v,w));
    adj[v].push_back(edge(u,w));
}

class binaryMinHeap{
private:
    vector<node> heap;
    unordered_map< int, int > pos;
    
    int size;
    int capacity;
public:
    binaryMinHeap(int n){
        heap.resize(n);
        size = 0;
        capacity = n;
    }
    ~binaryMinHeap(){
        heap.clear();
        pos.clear();
    }
    
    node min(){
        return heap[0];
    }
    
    void heapify( int i ){
        int min, c1, c2;
        c1 = 2*i+1;
        c2 = 2*i+2;
        
        if( c1 < size && c2 < size ){
            min = (heap[c1].priority < heap[c2].priority)? c1: c2;
        }
        else if( c1 < size ){
            min = c1;
        }
        else
            return;
        
        while( heap[i].priority > heap[min].priority ){
            node temp = heap[min];
            heap[min] = heap[i];
            heap[i] = temp;
            
            pos[heap[i].vertice] = i;
            pos[heap[min].vertice] = min;
            
            i = min;
            
            c1 = 2*i+1;
            c2 = 2*i+2;
            
            if( c1 < size && c2 < size ){
                min = (heap[c1].priority < heap[c2].priority)? c1: c2;
            }
            else if( c1 < size ){
                min = c1;
            }
            else
                return;
            
        }
        
    }
    
    void insert(node n){
        int t = size;
        heap[t] = n;
        pos[heap[t].vertice] = t;
        size++;
        node temp;
        while( t != 0 && heap[t].priority < heap[(t-1)/2].priority ){
            temp = heap[(t-1)/2];
            heap[(t-1)/2] = heap[t];
            heap[t] = temp;
            
            pos[heap[t].vertice] = t;
            pos[heap[(t-1)/2].vertice] = (t-1)/2;
            
            t = (t-1)/2;
        }
    }
    
    bool contain( int vertex ){
        if(pos.count(vertex) > 0 )
            return true;
        else
            return false;
    }
    
    node extract_min(){
        node temp = heap[0];
        heap[0] = heap[size-1];
        pos[heap[0].vertice] = 0;
        size--;
        heapify(0);
        pos.erase(temp.vertice);
        return temp;
    }
    
    bool isEmpty(){
        return size==0;
    }
    
    void decrease_key( int vertex, int m ){
        int p = pos[vertex];
        heap[p].priority = m;
        node temp;
        while( p != 0 && heap[p].priority < heap[(p-1)/2].priority ){
            temp = heap[(p-1)/2];
            heap[(p-1)/2] = heap[p];
            heap[p] = temp;
            
            pos[heap[p].vertice] = p;
            pos[heap[(p-1)/2].vertice] = (p-1)/2;
            
            p = (p-1)/2;
        }
    }
    
    void increase_key( int vertex, int m){
        int p = pos[vertex];
        heap[p].priority = m;
        heapify(p);
    }
    
    void print(){
        cout<<"Size: "<<size<<endl;
        for(int i = 0; i < size; i++)
            cout<<heap[i].vertice<<" ";
        cout<<endl;
    }
    
    int key(int vertex){
        int p = pos[vertex];
        return heap[p].priority;
    }
};

void primMST(list<edge> adj[], int v ){
    binaryMinHeap Q(v);
    vector<int> parent(v, -1);
    
    Q.insert(node(0,0));
    for( int i = 1; i < v; i++ ){
        Q.insert(node(i,INT_MAX));
    }
    
    while( !Q.isEmpty() ){
        node n_u = Q.extract_min();
        int u = n_u.vertice;
        for( auto itr = adj[u].begin(); itr != adj[u].end(); itr++ ){
            int v = (*itr).v;
            int wt = (*itr).wt;
            if( Q.contain(v) ){
                if( Q.key(v) > wt ){
                    Q.decrease_key(v, wt );
                    parent[v] = u;
                }
            }
        }
    }
    
    cout<<"Edges in MST:"<<endl;
    for( int i = 1; i < v ; i++ ){
        cout<<i<<"---"<<parent[i]<<endl;
    }
    
}


int main(){
    int v = 9;
    list<edge> adj[v];
    
    addEdge(adj, 0, 1, 4);
    addEdge(adj,0, 7, 8);
    addEdge(adj,1, 2, 8);
    addEdge(adj,1, 7, 11);
    addEdge(adj,2, 3, 7);
    addEdge(adj,2, 8, 2);
    addEdge(adj,2, 5, 4);
    addEdge(adj,3, 4, 9);
    addEdge(adj,3, 5, 14);
    addEdge(adj,4, 5, 10);
    addEdge(adj,5, 6, 2);
    addEdge(adj,6, 7, 1);
    addEdge(adj,6, 8, 6);
    addEdge(adj,7, 8, 7);
    
    
    primMST(adj, v);
    
    return 0;
}
