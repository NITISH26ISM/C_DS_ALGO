# include <stdio.h>
# include <stdlib.h>

void findPair(int arr[], int size, int pivot,int x){
    int low = 0, high = size - 1,sum = 0, flag = 0;
    while( low < high ){
        sum = arr[ ( low + pivot )%size ] + arr[ (high + pivot)%size ];
        if(sum == x){
            flag = 1;
            printf("\npair found: %d %d\n",arr[ ( low + pivot )%size ], arr[ (high + pivot)%size ] );
            low = low + 1;
            high = high - 1;
        }
        else if(sum > x){
            high = high - 1;
        }
        else{
            low = low + 1;
        }
    }
    
    if(!flag){
        printf("pair not found!\n");
    }
}


int pivotFind(int arr[], int size){
    int low = 0, high = size - 1, mid , pivot = 0;;
    while(low != high){
        mid = (low + high) / 2;
        if ( arr[mid] > arr[0] )
        {
            if( arr[mid] < arr[mid + 1] ){
                 low = mid + 1;
            }
            else{
                 return mid + 1;
            }
        }
        else{
            high = mid;
        }
        
    }
    return pivot;
}


void printArray(int arr[], int size){
    printf("\nPrint Array: ");
    for(int i = 0 ; i < size-1; i++ )
        printf("%d, ",arr[i]);
    printf("%d \n",arr[size - 1]);
}


int main(){
    int arr[] = {11, 15, 26, 38, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr,size);
    int pivot = pivotFind(arr, size);
    //printf("pivot %d\n",pivot);
    findPair(arr, size, pivot, 35);
    return 0;
}
