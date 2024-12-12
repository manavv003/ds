#include<stdio.h>

void main()
{	
	void merge(int a[],int,int,int);
	void merge_sort(int a[],int,int);
	void m_print(int a[10],int);

	int a[10];
	int i,n,frist,end;

	printf("\n Enter the number of element :: ");
	scanf("%d",&n);
	
	frist = 0;
	end = n-1;

	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}

	merge_sort(a,frist,end);
	m_print(a,n);
}

void merge(int a[10],int frist,int mid,int end)
{	
	int i,j,k,b[10],temp;

	i = frist;
	j = mid+1;
	temp = frist;

	while(i <= mid && j<= end)
	{
		if(a[i] < a[j])
		{
			b[temp] = a[i];
			i++;
		}
		else
		{
			b[temp] = a[j];
			j++;
		}
		temp++;
	}

	if(i > mid)
	{
		while(j <= end)
		{
			b[temp] = a[j];
			j++;
			temp++;
		}
	}
	else
	{
		while(i <= mid)
		{
			b[temp] = a[i];
			i++;
			temp++;
		}
	}

	for(k = frist; k < temp; k++)
	{
		a[k] = b[k];
	}
}

void merge_sort(int a[10],int frist,int end)
{
	int mid;

	if(frist < end)
	{
		mid = (frist + end)/2;
		merge_sort(a,frist,mid);
		merge_sort(a,mid+1,end);
		merge(a,frist,mid,end);
	}
}

void m_print(int a[10],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
}
