//Using Recusrion Linear Serach
#include <stdio.h>
#include <stdlib.h>

int LinearSerach(int arr[],int n,int key,int i){
    if(i==n){
        return -1;
    }
     if(arr[i] == key){
        return i;
     }
        return LinearSerach(arr,n,key,i+1);
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
    int result = LinearSerach(arr,n,key,0);
    if(result == -1){ 
        printf("Element not found");
    }
    else{
        printf("Element found at index %d",result);
    }
}

