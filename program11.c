 /*Write A Menu Driven Program

1. To Create 4 Functions For Bubble Sort, Selection sort, Insertion Sort, Merge Sort
2. Before Calling The Sort Function Initilaize The Array With Random Inputs.
3. Find Out the Execution Time For The Same Input Clock() Function. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void input(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("\n Enter the Array Size \n");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    printf("\nOriginal Array:\n");
    display(arr, n);
    int choice;
    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("\nEnter Your Choice\n");
    scanf("%d", &choice);
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("\nArray After Bubble Sort:\n");
            display(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nArray After Selection Sort:\n");
            display(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nArray After Insertion Sort:\n");
            display(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            printf("\nArray After Merge Sort:\n");
            display(arr, n);
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
    }
    
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken By The Program Is %f seconds\n", cpu_time_used);
    
    return 0;
}



