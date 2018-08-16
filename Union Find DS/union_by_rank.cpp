//union by rank with optimized path compression
// amrotise constant time;
# include <iostream>
# include <vector>

using namespace std;

struct set{
    int parent;
    int rank;
};

class DisjointSet{
private:
    vector<set> subsets;
public:
    DisjointSet( int n ){
        subsets.resize(n);
    }
    
    void makeSet( vector<int> const &universe ){
        for( int i : universe ){
            subsets[i].parent = i;
            subsets[i].rank = 1;
        }
    }
//     less optimized find function
//     int Find1( int k ){
//         while( subsets[k].parent != k ){
//             subsets[k].parent = subsets[subsets[k].parent].parent;
//             k = subsets[k].parent;
//         }
//         
//         return k;
//     }
    
    int Find( int k ){
        int r = k;
        while( r != subsets[r].parent ){
            r = subsets[r].parent;
        }
        int p;
        while( k != subsets[k].parent ){
            p = subsets[k].parent;
            subsets[k].parent = r;
            k = p;
        }
        
        return r;
    }
    
    void Union( int a, int b ){
        int x = Find(a);
        int y = Find(b);
        
        if( subsets[x].rank < subsets[y].rank ){
            subsets[x].parent = y;
            subsets[y].rank += subsets[x].rank; 
        }
        else{
            subsets[y].parent = x;
            subsets[x].rank += subsets[y].rank;
        }
        
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
    
    DisjointSet ds(6);
    
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
