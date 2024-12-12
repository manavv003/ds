//pract - 8 two matrix using pointer
#include<stdio.h>
void main()
{
	int *m[2][2];
	int *m1[2][2];
	int *m2[2][2];
	void printmat(int *m[2][2],int *m1[2][2],int *m2[2][2]);	
	int i,j;
	printf("Enter the first matrix : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		m1[i][j]=(int *)malloc(sizeof(int));
		
		scanf("%d",m1[i][j]);
		
		}
		printf("\n");
	}
	printf("Enter the second matrix : \n");
	for(i=0;i<2;i++)
	{		
		for(j=0;j<2;j++)
		{
			m2[i][j]=(int *)malloc(sizeof(int));			
			scanf("%d",m2[i][j]);	
		}		
		printf("\n");		
	}	
	printmat(m,m1,m2);
}
void printmat(int *m[2][2],int *m1[2][2],int *m2[2][2])
{
	int i,j;
	printf("Sum of Two Matrix....\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		 m[i][j]=(*m1[i][j])+(*m2[i][j]);		 
		 printf("%d\t",m[i][j]);		 	
		}
		printf("\n");		
	}		
}
