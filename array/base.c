# include <stdio.h>
# include <stdlib.h>



void printArray(int arr[], int size){
    printf("\nPrint Array: ");
    for(int i = 0 ; i < size-1; i++ )
        printf("%d, ",arr[i]);
    printf("%d \n",arr[size - 1]);
}


int main(){
    int arr[] = {1, 2 ,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr,size);
    
}
