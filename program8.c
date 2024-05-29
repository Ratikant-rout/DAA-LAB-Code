/*Implementation Of Bubble Sort , Selection Sort
Write A Menu Driven Program Having The Following Option
1. INPUT - Read The Array
2. OUTPUT - Display The Array
3. BUBBLE SORT - ASCENDING ORDER
4. Selection Sort - DESCENDING ORDER
6. INSERTION SORT - ASCENDING

*/


#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    int choice;
    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    printf("\nEnter Your Choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            bubbleSort(arr,n);
            printf("\nArray After Bubble Sort\n");
            for(int i=0; i<n; i++){
                printf("%d : ",arr[i]);
            }
            break;
        case 2:
            selectionSort(arr,n);
            printf("\nArray After Selection Sort\n");
            for(int i=0; i<n; i++){
                printf("%d : ",arr[i]);
            }
            break;
        case 3:
            insertionSort(arr,n);
            printf("\nArray After Insertion Sort\n");
            for(int i=0; i<n; i++){
                printf("%d : ",arr[i]);
            }
            break;
        default:
            printf("\nInvalid Choice\n");
    }
    return 0;
}

