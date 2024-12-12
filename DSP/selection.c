//program - 15  selection sort.
#include<stdio.h>
int main()
{
    int a[5]= {16,7,11,9,8};
    int temp;
    int i, j;  
    
     printf("Before Sorting \n");
    
    for(i=0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    
    for(i=0; i<5; i++)
    {
        for(j=i+1; j<5; j++)
		 { 
		 	if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
     printf("\nAfter Sorting \n");
    for(i=0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
