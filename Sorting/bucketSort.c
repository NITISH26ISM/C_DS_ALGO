# include <stdio.h>
# include <stdlib.h>
# define M 100

typedef struct node{
    int data;
    struct node* next;
}node;

void bucketSort( int arr[], int size ){
    int s[M];
    node* tail[M];
    for(int i = 0; i < M; i++){
        s[i] = -1;
        tail[i] = NULL;
    }
    
    for( int i = 0; i<)
}

//Testing and Debugging
int main(){
    int arr[] = {2,45,36,78,12,45,96,78,36,45,36,95,42,3,6,44,77,88,99,33,4,5,5,5,4,5,6,3,5,78,96,91,37,82,46,55,39,28,17,93,8,27,17,79,46,13,31,64,97,99};
    int size = sizeof(arr)/sizeof(int);
    bucketSort( arr, size );
    for(int i = 0; i < size; i++)
        printf( "%d ", arr[i] );
    
    printf("\n");
}
