//naive implementation of union find algorithm
// bad algorithm as bad as a linked list


# include <iostream>
# include <unordered_map>
# include <vector>

using namespace std;

class DisjointSet{
    unordered_map<int , int> parent;
public:
    void makeSet( vector<int> const &universe ){
        for( int i : universe){
            parent[i] = i;
        }
    }
    
    int Find(int k){
        if(parent[k] == k)
            return k;
        
        return Find( parent[k] );
    }
    
    void Union( int a, int b ){
        int x = Find(a);
        int y = Find(b);
        
        parent[x] = y;
    }
    
};

void printSets( vector<int> const &universe, DisjointSet ds ){
    for( int i : universe ){
        cout<<ds.Find(i)<<" ";
    }
    cout<<"\n";
}

int main(){
    vector<int> universe = {1,2,3,4,5};
    
    DisjointSet ds;
    
    ds.makeSet(universe);
    printSets( universe, ds );
    
    ds.Union(4,3);
    printSets( universe, ds );
    
    ds.Union(2,1);
    printSets( universe, ds );
    
    ds.Union(1,3);
    printSets( universe, ds );
    
    return 0;
    
}
