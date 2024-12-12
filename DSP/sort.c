//pract - 10 Sort array using pointer
#include<stdio.h>
void main()
{
	void read(int *);
	void sort(int *);
	void print(int *);
	
	int *ip,arr[10];
	
	ip=arr;
	read(ip);
	sort(ip);
	print(ip);
}

void read(int *ip)
{
	int i;
	printf("enter element : \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",(ip+i));
	}
}

void sort(int *ip)
{
	int i,j,temp;
	for(i=0;i<9;i++)
	{
	    for(j=i+1;j<10;j++)
	    {
	         if(*(ip+i)>*(ip+j))
	         {
	         	temp=*(ip+i);
	         	*(ip+i)=*(ip+j);
	         	*(ip+j)=temp;
			 }
     	}
	}
}

void print(int *ip)
{
	int i;
	printf("sorted element \n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",*(ip+i));
	}
}

