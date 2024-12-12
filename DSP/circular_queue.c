//circular queue prog-5
#include<stdio.h>
#define max 5
int CQ[max];
void main()
{
	
	int choice,ele,Remove;
	int *front;
	int *rear;
	
	void CQ_Insert(int *,int *,int ele);
	void CQ_Delete(int *,int *);
	void CQ_Display(int *,int *);

	front=(int *)malloc(sizeof(int));
	rear=(int *)malloc(sizeof(int));

	*front=-1;
	*rear=-1;
	while(1)
	{
		printf("1 . Insert \n");
		printf("2 . Delete \n");
		printf("3 . Display \n");

		printf("Enter Your Choice: \n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:{
				printf("Enter Your Element: ");
				scanf("%d",&ele);
				CQ_Insert(front,rear,ele);
				break;
			   }
		case 2:{
				CQ_Delete(front,rear);
				break;
			   }
		case 3:{
				CQ_Display(front,rear);
				break;
			   }
		case 4:
			exit(1);
			break;
		}
	}
}
void CQ_Insert(int *front,int *rear,int ele)
{
	if((*front)==-1 && (*rear)==-1)
	{
		(*front)=(*rear)=0;
		CQ[(*rear)]=ele;
	}
	else
	{
		if(((*rear)==max-1 && (*front)==0 )||((*front)-(*rear)==1))
		{
			printf("Circular Queue Is Full \n");
		}
		else
		{
			if((*rear)==max-1)
			{
				(*rear)=0;
				CQ[(*rear)]=ele;
			}
			else
			{
				(*rear)=(*rear)+1;
				CQ[(*rear)]=ele;
			}
		}
	}
}
void CQ_Delete(int *front,int *rear)
{	int Remove;
	if((*rear)==-1 && (*front)==-1)
	{
		printf("Circular Queue is Empty \n");
	}
	else
	{
		if((*front)==(*rear))
		{
			printf("from");
			Remove=CQ[(*front)];
			(*front)=(*rear)=-1;
			printf("Removed Value is %d \n",Remove);
		}
		else
		{
			Remove=CQ[(*front)];
			(*front)=(*front)+1;

		/*	if((*front)==max-1)
			{
				(*front)=0;
			}*/
			printf("Removed Value is %d \n",Remove);
		}
	}
}
void CQ_Display(int *front,int *rear)
{	int i;

	//printf("%d",(*rear));
	if((*front)==-1 && (*rear)==-1)
	{
		printf("Circular Queue is Empty \n");
	}
	else
	{
		for(i=(*front);i<=(*rear);i++)
		{
			printf("%d \n",CQ[i]);
		}
	}
}
