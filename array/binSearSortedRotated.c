# include <stdio.h>
# include <stdlib.h>



void printArray(int arr[], int size){
    printf("\nPrint Array: ");
    for(int i = 0 ; i < size-1; i++ )
        printf("%d, ",arr[i]);
    printf("%d \n",arr[size - 1]);
}

int binarySearch(int arr[], int key, int low, int high){
    int pivot = 0,mid;
    int l = low , h = high;
    int size = high + 1;
    //find the pivot
    
    while(low != high){
        mid = (low + high)/2;
        
        if(arr[mid] > arr[0]){
            if(arr[mid] < arr[mid+1])
                low = mid+1;
            else
            {
                pivot = mid+1;
                break;
            }
        }else{
            high = mid-1 ;
        }
    }
    
    printf("\npivot: %d\n",pivot);
    
    while( l <= h){
        mid = (l+h)/2;
        if(arr[ ( mid + pivot )%size ] == key )
        {
            printf("key found at index %d",( mid + pivot )%size);
            return mid;
        }
        else if( arr[ ( mid + pivot )%size ] > key ){
                h = mid-1;
        }
        else
            l = mid+1;
    }
    
}

int main(){
    int arr[] = {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1, 2 ,3,4};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr,size);
     int key = 5;
    binarySearch(arr, key,0,19);
}

