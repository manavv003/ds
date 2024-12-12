//double queue prog-4
#include<stdio.h>
#define max 10
int DQ[max];
void main()
{
	
	int choice,ele,Remove;
	int *front;
	int *rear;
	
	void DQ_Insert(int *,int *,int ele);
	void DQ_Delete(int *,int *);
	void DQ_Display(int *,int *);

	front=(int *)malloc(sizeof(int));
	rear=(int *)malloc(sizeof(int));

	*front=-1;
	*rear=-1;
     
	while(1)
	{
		
			printf("1 . Insert \n");
	    	printf("2 . Delete \n");
	    	printf("3 . Display \n");
	    	printf("4. Exit \n");
	    	
	    		printf("Enter Your Choice: ");
	        	scanf("%d",&choice);
	    	
		switch(choice)
		{
		case 1:{
				printf("Enter Your Element: ");
				scanf("%d",&ele);
				DQ_Insert(front,rear,ele);
				break;
			   }
		case 2:{
				DQ_Delete(front,rear);
				break;
			   }
		case 3:{
				DQ_Display(front,rear);
				break;
			   }
			   case 4:{
				exit(0);
				break;
			   }
		
		}
		
	}
}
void DQ_Insert(int *front,int *rear,int ele)
{
	if((*front)==-1 && (*rear)==-1)
	{
		(*front)=(*rear)=0;
		DQ[(*rear)]=ele;
	}
	else
	{
			if((*rear)==max-1)
			{
				printf("Queue is full");
			}
			else
			{
				(*rear)=(*rear)+1;
				DQ[(*rear)]=ele;
			}
		
	}
}
void DQ_Delete(int *front,int *rear)
{	int Remove,choice;
     printf("Enter 1 for remove element from front \n Enter 2 for remove element from  end \n");
     printf("enter your choice : ");
     scanf("%d",&choice);
	if((*rear)==-1 && (*front)==-1)
	{
		printf("Circular Queue is Empty \n");
	}
	else
	{
		if(choice==1)
		{
				if((*front)==(*rear))
	        	{
						printf("from");
						Remove=DQ[(*front)];
						(*front)=(*rear)=-1;
							printf("Removed Value is %d \n",Remove);
				}
				else
				{
						Remove=DQ[(*front)];
						(*front)=(*front)+1;
							printf("Removed Value is %d \n",Remove);
				}
			
		}
		else
		{
			Remove=DQ[(*rear)];
			(*rear)=(*rear)-1;

				printf("Removed Value is %d \n",Remove);
		}
		
   }
}
void DQ_Display(int *front,int *rear)
{	int i,choice;
      printf("Enter 1 for disply element from front \n Enter 2 for displsy element from  end \n");
      printf("enter your choice : ");
     scanf("%d",&choice);
	if(choice==1)
    {
	    for(i=(*front);i<=(*rear);i++)
		{
			printf("%d \n",DQ[i]);
		}
    }
    else
	{
		for(i=(*rear);i>=(*front);i--)
		{
			printf("%d \n",DQ[i]);
		}
	}
}
