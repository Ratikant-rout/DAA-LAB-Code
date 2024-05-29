//implemt binary serach
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarysearch(int arr[], int n, int key)
{

    int low = 0;
    int high = n - 1;

    for (int i = 0; i < n; i++)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    int n;
    printf("Enter The Elements oF The Array : ");
    scanf("%d", &n);
    int arr[n];
    int key;
    int low = 0;
    int high = n - 1;
    printf("Enter The Elements Of The Array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Key Element To be Searched : ");
    scanf("%d", &key);

    int result = binarysearch(arr, key, n);

    printf("Element Found At Index : %d", arr[idx]);
}