# include <stdio.h>
# include <stdlib.h>


int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1,j,temp;
    for(j = low ; j <= high-1; j++){
        if(arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}


void quicksort(int arr[], int low, int high){
    if(low < high){
        int  pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}


int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    quicksort(arr,0 ,5);
    for(int i = 0 ; i <= 5 ;i++ )
        printf("%d ",arr[i]);
}
