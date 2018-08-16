# include <stdio.h>


void insertionSort(int arr[], int n){
    int i = 0, j,temp;
    for( i = 1;  i < n; i++ ){
        j = i;
        temp = arr[i];
        while( temp < arr[j-1] && j >= 0 ){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
    
}


int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    insertionSort(arr, n);
    
    for(int i = 0 ; i < n; i++)
        printf("%d ",arr[i]);
 
    return 0;
}
