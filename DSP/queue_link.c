#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void main()
{
	void insert_linked(struct node **, int );
	void delete_linked(struct node ** );
	void display_linked(struct node ** );
	
	struct node **top;
	int val;
	int choice;
	
	top=(struct node ** )malloc(sizeof(struct node *));
	*(top)=NULL;
	
	while(1)
	{
		printf("\n 1.Insert");
		printf("\n 2.Delete");
		printf("\n 3.Display");
		
		printf("\n Enter choice :- \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:{
					printf("Enter value :-");
					scanf("%d",&val);
					insert_linked(top,val);
					break;
			   }
		case 2:{
					delete_linked(top);	
					break;
			   }
		case 3:{
					display_linked(top);
					break;
			   }
		case 4: exit(0);
				break;
					
		default	: printf("------------Invalid Choice-----------\n");
				 break;	
		}
	}
}
void insert_linked(struct node **top , int val)
{
	struct node *newnode,*curr;
	
	newnode=(struct node *)malloc(sizeof(struct node *));
	curr=*(top);
	
	newnode->data=val;
	newnode->next=NULL;

	if(curr==NULL)
	{
		*(top)=newnode;
	}
	else
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;	
		}
		curr->next=newnode;
	}	
}
void delete_linked(struct node **top )
{
	struct node *curr;
	if(*(top)==NULL)	
	{
		printf("\n Queue is  Empty ");
	}
	else
	{
		curr=*(top);
		*(top)=curr->next;

		printf("\n Delete Value is :- %d ",curr->data);
		free(curr);
	}
}
void display_linked(struct node **top )
{
	struct node *curr;
	curr=*(top);
		
	if(curr==NULL)
	{
		printf("\n  Queue is Empty");
	}
	else
	{
		printf("\n Display Value is:");
		while(curr!=NULL)
		{
			printf("\n %d ",curr->data);
			curr=curr->next;
		}
	}
	printf("\n");
}
