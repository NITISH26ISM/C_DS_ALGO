# include <stdio.h>
# include <stdlib.h>


int maxSum(int arr[], int size){
    int sum = 0;
    for(int i  = 0 ; i < size; i++ )
        sum = sum + arr[i];
    
    int max = 0, curr = 0;
    for( int i = 0; i < size ; i++ )
        max = max + i * arr[i];
    
    curr = max;
    for(int i = size-1; i >= 0 ; i-- ){
        curr = curr + sum - (size) * arr[i];
        if(curr > max)
            max = curr;
    }
    
    return max;
}

void printArray(int arr[], int size){
    printf("\nPrint Array: ");
    for(int i = 0 ; i < size-1; i++ )
        printf("%d, ",arr[i]);
    printf("%d \n",arr[size - 1]);
}


int main(){
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr,size);
    printf("%d", maxSum(arr,size));
    return 0;
}
