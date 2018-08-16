# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>

using namespace std;

void addEdge(vector<vector<int> >&v, vector<vector<int> > &next, int a, int b, int w ){
    v[a][b] = w;
    next[a][b] = b;
}

void propagateNegativeCycles( vector<vector<int> > &v,vector<vector<int> > &next, int n ){
    for( int k = 0; k < n; k++ ){
        for(int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if( v[i][k] != INT_MAX && v[k][j] != INT_MAX && v[i][j] > v[i][k] + v[k][j] ){
                    v[i][j] = INT_MIN;
                    next[i][j] = -1;
                }
            }
        }
    }
}

void flyodWarshall( vector<vector<int> > &v, vector<vector<int> > &next, int n){
    for( int k = 0; k < n; k++ ){
        for(int i = 0; i < n ; i++ ){
            for(int j = 0; j < n; j++ ){
                if( v[i][k] != INT_MAX && v[k][j] != INT_MAX && v[i][j] > v[i][k] + v[k][j] ){
                    v[i][j] = v[i][k] + v[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    
   // propagateNegativeCycles( v, next, n );
}

vector<int> pathReconstruction( vector<vector<int> > &v, vector<vector<int> > &next, int start, int end ){
    vector<int> path;
    
    if( v[start][end] == INT_MAX ){
        return path;
    }
    
    int at = start;
    for( ; at != end ; at = next[at][end] ){
        if( at == -1 ){
            path.clear();
            return path;
        }
        path.push_back(at);
    }
    
    if( next[at][end] == -1){
        path.clear();
        return path;
    }
    path.push_back(end);
    return path;
}

int main(){
    int n = 5;
    vector<vector<int> > v;
    vector<vector<int> > next;
    v.resize(n);
    next.resize(n);
    //cout<<"fuck \n";
    for( int i = 0; i < 5; i++ ){
        v[i] = vector<int> (n);
        next[i] = vector<int> (n);
        fill(v[i].begin(), v[i].end(), INT_MAX );
        fill(next[i].begin(), next[i].end(), -2);
        v[i][i] = 0;
    }
    
    addEdge(v, next, 0, 2 , 6 );
    addEdge(v, next, 0, 3 , 3 );
    addEdge(v, next, 1, 0 , 3 );
    addEdge(v, next, 2, 3 , 2 );
    addEdge(v, next, 3, 1 , 1 );
    addEdge(v, next, 3, 2 , 1 );
    addEdge(v, next, 4, 1 , 4 );
    addEdge(v, next, 4, 3 , 2 );
    //addEdge(v,  ,  ,  );
    
   // cout<<"u\n";
    
    flyodWarshall( v, next, n );
    cout<<"\t";
    for( int i =0 ; i < n ; i++){
        cout<<i<<"\t";
    }
    cout<<endl;
    for( int i = 0; i < n; i++)
    {
        cout<<i<<":\t";
        for( int j = 0; j < n; j++ ){
            if( v[i][j] == INT_MAX )
                cout<<"inf\t";
            else if(v[i][j] == INT_MIN )
                cout<<"-inf\t";
            else
                cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    //////////////////////////////////////
    int start, end, flag = 1;
    char in;
    while( flag ){
        cout<<"Input: Start End: ";
        cin>>start>>end;
        vector<int> p = pathReconstruction( v, next, start, end);
        for( int i = 0; i < p.size(); i++ ){
            cout<<p[i]<<" ";
        }
        getchar();
        cout<<"\nPress y to Continue? ";
        in = getchar();
        flag = 0;
        p.clear();
        if(in == 'y')
            flag = 1;
    }
    
}
