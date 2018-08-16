# include <stdio.h>
# include <stdlib.h>


typedef struct heap{
    int *h;
    int size;
    int capacity;
}heap;


void init_heap( heap* Heap ,int cap){
    Heap->h = ( int* )malloc( ( cap + 1 ) * sizeof(int) );
    Heap->size = 0;
    Heap->capacity = cap;
}

void insert( heap *h, int p ){
    if( h->size == h->capacity ){
        int cap = h->capacity * 2;
        int *temp = ( int* )malloc( ( cap + 1 ) * sizeof(int) );
        for( int i = 1; i <= h->capacity ; i++)
            temp[i] = h->h[i];
        h->capacity = cap;
        free(h->h);
        h->h = temp;
    }
    h->size++;
    h->h[h->size] = p;
    int t = h->size, tmp;
    while( t != 1 && h->h[t] < h->h[t/2]){
        tmp = h->h[t];
        h->h[t] = h->h[t/2];
        h->h[t/2] = tmp;
        t = t/2;
    }
}

int minimum( heap* h ){
    return h->h[1];
}

void heapify( heap *h, int i){
    
    int c1, c2, m;
    c1 = i << 1;
    c2 = (i<<1) + 1;
    
    if( c1 <= h->size && c2 <= h->size )
        m = ( h->h[c1] < h->h[c2] )? c1 : c2 ;
    else if( c1 <= h->size )
        m = c1;
    else
        return;
    
    while( 1 ){
        if( h->h[i] <= h->h[m] )
            return;
        else{
            int tmp = h->h[i];
            h->h[i] = h->h[m];
            h->h[m] = tmp;
            i = m;
        }
        
        c1 = 2*i;
        c2 = 2*i + 1;
       
        if( c1 <= h->size && c2 <= h->size )
            m = ( h->h[c1] < h->h[c2] )? c1 : c2 ;
        else if( c1 <= h->size )
            m = c1;
        else
            return;
        
    }
}

int del_min( heap* h ){
    int r = h->h[1];
    h->h[1] = h->h[h->size];
    h->size--;
    heapify( h, 1 );
    return r;
}

void build_heap( heap* h, int  arr[]){
    for( int i = 1; i <= h->capacity; i++){
        h->h[i] = arr[i-1];
        h->size++;
    }

    
    int n = h->size;
    n = n/2;
    for( int i = n ; i >= 1; i--){
        heapify( h, i );
    }
}


int main(){
    heap H;
    int arr[] = { 43, 23, 26, 21, 48, 17, 13, 19, 17, 11 };
    int size = sizeof(arr) / sizeof(int);
    init_heap( &H, size );
    
    build_heap( &H, arr);
    
    for(int i = 1; i <= H.size; i++ )
        printf("%d ", H.h[i]);
    
    printf("\nminimum: %d\n", minimum(&H) );
    del_min(&H);
    for( ; H.size != 0 ; )
        printf("\nminimum: %d\n", del_min(&H) );
    
    return 0;
}
