//SOrt A Given Array In Ascending Order Using Heap Sort Algorithm.
//IMplement The Functions MaxHeapify and BuildMaxHeap.
//Heap Sort. 
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[],int n,int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
     if(r < n && arr[r] > arr[largest]){
        largest = r;
     }
      if(largest != i){
         swap(&arr[i],&arr[largest]);
        maxHeapify(arr,n,largest);
   }
}
 
 void buildmaxheap(int arr[],int n){
     for(int i=n / 2 - 1; i >= 0; i--){
          maxHeapify(arr,n,i);
     }
 }

  void heapsort(int arr[],int n){
     buildmaxheap(arr,n);
     for(int i= n - 1; i > 0; i--){
         swap(&arr[0] , &arr[i]);
           maxHeapify(arr,i,0);
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

    heapsort(arr,n);

    printf("\nArray After Sorting\n");
    for(int i=0; i < n; i++){
        printf("%d : ",arr[i]);
    }
    return 0;
}



  
 
  

