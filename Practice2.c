#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Corrected index to j
                arr[j] = arr[j + 1]; // Corrected index to j
                arr[j + 1] = temp; // Corrected index to j+1
            }
        }
    }
}


int main(){
    int n;
    printf("Enter The Elements oF The Array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Elements Of The Array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int result = bubbleSort(arr,n);

    for(int i=0; i<n; i++){
        printf("%d",arr[i]);
    }
}