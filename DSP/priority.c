//pract-11 Priority queue
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 10
int Q1[10];
int Q2[10];
void main()
{
	void insert(int *nf,int *sf , int *nr ,int *sr ,int ele);
	int q_del(int *nf,int *sf , int *nr ,int *sr);
	void traverse(int *nf,int *sf , int *nr ,int *sr);
	
	int *nf,*nr,*sf,*sr;
	nf=(int *)malloc(sizeof(int));
	sf=(int *)malloc(sizeof(int));
	nr=(int *)malloc(sizeof(int));
	sr=(int *)malloc(sizeof(int));
	 *nf=-1;
	 *sf=-1;
     *nr=-1;
     *sr=-1;
	int ele,choice,rem;
	
	while(1)
	{
		printf("\n 1.Insert Number :");
		printf("\n 2.Remove Number :");
		printf("\n 3.Display Number :");
		
		printf("\n Enter Your Choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 :{
				printf("\n Enter Your Number :");
				scanf("%d",&ele);
				insert(nf,sf,nr,sr,ele);
				break;
			}
			case 2 :{
				rem=q_del(nf,sf,nr,sr);
				printf("%d",rem);
				break;
			}
			case 3:{
				traverse(nf,sf,nr,sr);
				break;
			}
		}
	}
}

void insert(int *nf,int *sf , int *nr ,int *sr,int ele)
{
	if(ele<=60)
	{
	if(*nf==-1 && *nr==-1)
	{
		*nf=*nr=0;
		Q1[*nr]=ele;
	}
	else
	{
		if(*nr>=max-1)
		{
			printf("\n Queu is Overflow");
		}
		else
		{
			(*nr)=(*nr)+1;
			Q1[*nr]=ele;
		}
	}
	}
	else 
	{
		if(*sf==-1 && *sr==-1)
		{
			(*sf)=(*sr)=0;
			Q2[*sr]=ele;
		}
		else
		{
			if(*sr>=max-1)
			{
				printf("\n Queu is Overflow");
			}
			else
			{
				(*sr)=(*sr)+1;
				Q2[*sr]=ele;
			}
		}
	}
}

int q_del(int *nf,int *sf , int *nr ,int *sr)
{
	int remove;
	if(*sf==*sr)
	{

	if(*nf==-1 &&*nr==-1)
	{
		printf("\n Queu is Empty");
	}
	else
	{
		if(*nf==*nr)
		{
			remove=Q1[*nf];
			(*nf)=(*nr)=-1;
		}
		else
		{
			remove=Q1[*nf];
			(*nf)=(*nf)+1;
		}
	}
	}
	else
	{
		if(*sf==-1 &&*sr==-1)
		{
			printf("\n Queu is Empty");
		}
		else
		{
			if(*sf==*sr)
			{
				remove=Q2[*sf];
				(*sf)=(*sr)=-1;
			}
			else
			{
				remove=Q2[*sf];
				(*sf)=(*sf)+1;
			}
		}
	}
	return remove;
}

void traverse(int *nf,int *sf , int *nr ,int *sr)
{
	int i,n;
	printf("Enter 1 display Senior :");
	scanf("%d",&n);
	if(n==1)
	{
	if(*sf==-1 && *sr==-1)
	{	
		printf("\n Queu is Empty");
	}
	else
	{
		for(i=*sf;i<=*sr;i++)
		{
			printf("\n %d",Q2[i]);
		}
		
	}	
	}
	else
	{
		if(*nf==-1 && *nr==-1)
		{
			printf("\n Queu is Empty");
		}
		else
		{
			for(i=*nf;i<=*nr;i++)
			{
				printf("\n %d",Q1[i]);
			}
		}
	}
}
