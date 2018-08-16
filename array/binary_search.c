# include <stdio.h>
# include <stdlib.h>


int binary_search_rec(int arr[], int low, int high, int key){
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if( key == arr[mid] ){
        printf("key found at index %d",mid);
        return mid;
    }
    else if (key < arr[mid]){
        return binary_search_rec(arr , low , mid-1,key);
    }
    else{
        return binary_search_rec(arr , mid+1, high,key);
    }
    
}

int binary_search(int *arr, int search_key, int size){
    int low = 0, high = size - 1, mid;
    
    while(low <= high){
        mid = (low + high)/2;
        if(search_key == arr[mid]){
            printf("\nkey found at %d index\n",mid);
            return mid;
        }
        else if(search_key < arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    
    printf("key not found\n");
    return -1;
}


void printArray(int arr[], int size){
    printf("\nPrint Array: ");
    for(int i = 0 ; i < size-1; i++ )
        printf("%d, ",arr[i]);
    printf("%d \n",arr[size - 1]);
}


int main(){
    int arr[] = { 1, 2 ,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int size = sizeof(arr) / sizeof(int);
    printArray(arr,size);
    int search_key = 5;
    
    binary_search_rec(arr,0,size-1, search_key);
    
}
