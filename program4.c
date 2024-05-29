//Binary Search Using Recursion
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[],int low,int high,int key){
    if(low<= high){
        int mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            return binarysearch(arr,mid+1,high,key);
        }
        else{
            return binarysearch(arr,low,mid-1,key);
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter The Size Of Array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Elements Of Array:");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter The Key:");
    scanf("%d",&key);
    int result = binarysearch(arr,0,n-1,key);
    if(result == -1){
        printf("Element not found");
    }
    else{
        printf("Element found at index %d",result);
    }
}