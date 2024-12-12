//program - 18 marge two sorted array into third array..
#include<stdio.h>
int main() 
{
    int arr1[] = {1, 3, 5, 7, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int mergedArr[n1 + n2];
    
    mergeArrays(arr1, n1, arr2, n2, mergedArr);
    
    printf("Merged Array: ");
    int i;
     for (i = 0; i <( n1 + n2) ;i++)
	{
        printf("%d ", mergedArr[i]);
    }
    
    return 0;
}
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int mergedArr[]) 
{
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) 
	{
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }
    
    while (i < n1) {
        mergedArr[k++] = arr1[i++];
    }
    
    while (j < n2) {
        mergedArr[k++] = arr2[j++];
    }
}

