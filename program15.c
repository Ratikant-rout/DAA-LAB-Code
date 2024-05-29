//implementation of franctional knapsack problem
//take input for some products each having information  1. product id, 2. product name 3.profit 4.weight
//using greedy algorithm to to find solution to accomodate the objects in knapsack of capacity W.
#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n){
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
  
   //implement fractional knapsack algorithm

  ++++
   