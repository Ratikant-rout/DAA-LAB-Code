/*1. Write A Program to take input for n number of random numbers and implement quick sort to sort in ascending order. Calculate The EXecution Time Of The Quick Sort Function. */
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int n;
    printf("\nEnter The Size Of An Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter The Elemnents Of An Array\n");
    for(int i=0; i<n; i++){
        scanf("%d : ", &arr[i]);
    }
    printf("\nArray Before Sorting\n");
    for(int i=0; i<n; i++){
        printf("%d : ",arr[i]);
    }

    clock_t start, end;
    start = clock();

    quicksort(arr,0,n-1);

    end = clock();

    printf("\nArray After Sorting\n");
    for(int i=0; i<n; i++){
        printf("%d : ",arr[i]);
    }

    printf("\nTime Taken To Sort The Array Is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
    
}