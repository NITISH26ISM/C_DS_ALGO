# include <stdio.h>
# include <stdlib.h>
# define MAX 9
# define t 5

typedef struct bNode{
    int n;
    int leaf;
    int key[ MAX + 2 ];
    struct bNode* c[ MAX + 2 ];
}bNode;


typedef struct pair{
    bNode *ptrNode;
    int index;
}pair;


typedef struct bTree{
    bNode* root;
}bTree;


pair* search( bNode *r, int k ){
    int i = 1;
    while( i <= r->n && k > r->key[i] )
        i++;

    if( i <= r->n && k == r->key[i] ){
        pair *p = ( pair* )malloc( sizeof( pair ) );
        p->ptrNode = r;
        p->index = i;
        return p;
    }

    else if( r->leaf )
        return NULL;
    else
        return search( r->c[i-1] , k);
}
//ok

void createTree(bTree *T){
    bNode *r = (bNode*)malloc(sizeof(bNode));
    r->n = 0;
    r->leaf = 1;
    T->root = r;
}

void splitChild(bNode* x, int ind){
    bNode *z = (bNode*)malloc(sizeof(bNode));
    bNode *y = x->c[ind-1];
    z->leaf = y->leaf;
    int mid = (MAX + 1)/2;
    for( int i = mid + 1; i <= y->n; i++){
        z->key[i-mid] = y->key[i];
        z->c[i-mid-1] = y->c[i-1];
    }
    z->c[ mid - 1 ] = y->c[MAX];
    
    y->n = mid-1;
    z->n = mid-1;
    
    for( int i = x->n; i >= ind ;  i-- ){
        x->key[i+1] = x->key[i];
        x->c[i+1] = x->c[i];
    }
    x->key[ind] = y->key[mid];
    x->c[ind-1] = y;
    x->c[ind] = z;
    x->n++;
}

void insertNonfull(bNode *x, int k){
    int i = x->n;
    if( x->leaf ){
        while( i >= 1 && k < x->key[i]){
            x->key[i+1] = x->key[i];
            i--;
        }
        x->key[i+1] = k;
        x->n++;
    }
    else{
            while( i >= 1 && k < x->key[i] )
                i--;
            
            if( x->c[i]->n == MAX){
                splitChild( x , i + 1 );
                if( k > x->key[i+1])
                    i++;
            }
            insertNonfull(x->c[i], k);
        }
}


void insert(bTree *T, int k){
    bNode *r = T->root;
    if( r->n == MAX){
        bNode *s = ( bNode* )malloc( sizeof(bNode) );
        T->root = s;
        s->leaf = 0;
        s->n = 0;
        s->c[0] = r;
        splitChild( s, 1);
        insertNonfull(s,k);
    }
    else
        insertNonfull(r,k);
}

void inorder(bNode *r){
    if(r->leaf){
        for( int i = 1; i <= r->n; i++)
            printf("%d ",r->key[i] );
        
        return;
    }
    for( int i = 0 ; i <= r->n ; i++){
        inorder(r->c[i]);
        if( i+1 <= r->n)
            printf("%d \n", r->key[i+1]);
    }
    return ;
}

int TreeMax( bNode *r ){
    while( r->leaf != 1 ){
        r = r->c[r->n];
    }
    return r->key[r->n];
}

int TreeMin( bNode *r ){
    while(r->leaf != 1){
        r = r->c[0];
    }
    return r->key[1];
}

void recDelete(bNode *x, int index){
    bNode *y = x->c[i-1];
    bNode *z = x->c[i];
    int kPrime;
    if( y->n >= t ){
        kPrime = TreeMax(y); 
        x->key[index] = kPrime;
        delete(T,kPrime)
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete( bTree *T, int k ){
    pair *p = search( T->root, k );
    bNode *x = p->y;
    int index = p->index;
    
    if(x->leaf){
        
        for( int i = index; i <= x->n ; i++ )
            x->key[i] = x->key[i+1];
        x->n--;
    }
    else{
            recDelete(x, index);
        }
    }
    
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Driver Program to run the main func.
int main(){
    bTree T;
    
    createTree(&T);
    
    for( int i = 1; i <= 999; i++)
        insert(&T, i);

    
    inorder(T.root);
    printf("\n");
    return 0;
}
