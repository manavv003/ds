#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;

    for (j= low; j <= high - 1; j++)
	{
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
	int pi;
    if (low < high) {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size) {
	int i;
    for ( i= 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    
    int n ;
    int arr[10];
    int i;
    
    printf("\n Enter Array Size :-");
   	scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
    	printf("\n Enter Array Value :-");
   		scanf("%d",&arr[i]);
    }
   
    printf("Original array: \n");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: \n");
    print_array(arr, n);

}

