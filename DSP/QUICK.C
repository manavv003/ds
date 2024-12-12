#include<stdio.h>

void main()
{

	void q_sort(int a[],int ,int);
	void q_print(int a[],int);
	
	int a[10];
	int i,ele,first,last;

	printf("Element the number :: ");
	scanf("%d",&ele);
	
	first = 0;
	last = ele-1;

	for(i=0;i<ele;i++)
	{
		printf("\n enter the Value arr[%d] :: ",i);
		scanf("%d",&a[i]);
	}

	q_sort(a,first,last);
	q_print(a,ele);
}

void q_sort(int a[10],int first,int last)
{
    int i, j, pivot, temp;

    if(first<last)
	{
        pivot = first;
        i = first;
        j = last;

        while(i < j)
		{
            while(a[i] <= a[pivot] && i < last)
			{
				 i++;
			}
            while(a[j] > a[pivot])
			{
				j--;
			}
            if(i < j)
			{
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        q_sort(a,first,j-1);
        q_sort(a,j+1,last);
    }
}

void q_print(int a[10],int ele)
{
	int i;

	for(i=0;i<ele;i++)
	{
	   printf("\n %d \n",a[i]);
	}
}
