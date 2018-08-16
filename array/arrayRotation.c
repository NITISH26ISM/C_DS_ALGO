# include <stdio.h>
# include <stdlib.h>


void rotate(int arr[], int d , int n){//time:O(n) space: O(d)
    int* a = (int *)malloc(d*sizeof(int));
    for(int i = 0; i < d; i++)
        a[i] = arr[i];
    
    for(int i = d; i < n  ; i++ )
        arr[i - d] = arr[i];
    
    for(int i = n - d, j = 0; i < n; i++,j++)
        arr[i] = a[j];
    
}

void rotate_fast(int arr[], int d, int n){
    int savedVal, index = 0, buffer;
    savedVal = arr[index];
    for( int count = 0 ; count < n; count++ ){
        buffer = arr[ (index + n - d) % n];
        arr[ (index + n - d) % n ] = savedVal;
        savedVal = buffer;
        index = (index + n - d)%n;
    }
}

void reverse(int arr[], int a , int b){
    int temp ;
    for(int i = a, j = b; i < j ; i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void rotate_rev(int arr[], int d, int n){
    reverse( arr, 0, d-1);
    reverse( arr, d, n-1 );
    reverse( arr, 0, n-1 );
}

int main(){
    int arr[] = { 1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int i = 0;
    for( i = 0; i < n; i++ )
        printf("%d, ",arr[i]);
    
    int d = 3;
    rotate_fast(arr, d, n);
    printf("\nrotated array: \n");
    for( i = 0; i < n; i++ )
        printf("%d, ",arr[i]);
}
