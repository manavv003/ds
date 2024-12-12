//priority queue using link list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void main()
{
	void insert_linked(struct node **, struct node **,int );
	void delete_linked(struct node ** ,struct node **);
	void display_linked(struct node **,struct node ** );
	
	struct node **top,**top2;
	int val;
	int choice;
	
	top=(struct node ** )malloc(sizeof(struct node *));
	top2=(struct node ** )malloc(sizeof(struct node *));
	
	*(top)=NULL;
	*(top2)=NULL;
	
	while(1)
	{
		printf("\n 1.Insert Value ...");
		printf("\n 2.Delete Value ...");
		printf("\n 3.Display Value ...");
		printf("\n Enter choice :- \n");
		scanf("%d",&choice);
		printf("\n ");
		switch(choice)
		{
		case 1:{
					printf("\n Enter value :-");
					scanf("%d",&val);
					insert_linked(top,top2,val);
					break;
			   }
		case 2:{
					delete_linked(top,top2);	
					break;
			   }
		case 3:{
					display_linked(top,top2);
					break;
			   }
		default:{
				  printf("\n Invalid Choice");
				  break;
				}
		}
	}
}

void insert_linked(struct node **top ,struct node **top2, int val)
{
	struct node *newnode;
	struct node *current;
	struct node *newnode2;
	struct node *current2;
	
	newnode=(struct node *)malloc(sizeof(struct node *));
	newnode2=(struct node *)malloc(sizeof(struct node *));
	current=*(top);
	current2=*(top2);
	if(val<60)
	{
			newnode->data=val;
			newnode->next=NULL;
		
			if(current==NULL)
			{
				*(top)=newnode;
			}
			else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				
				}
				current->next=newnode;
			}
   }
   else
   {
   	        newnode2->data=val;
			newnode2->next=NULL;
		
			if(current2==NULL)
			{
				*(top2)=newnode2;
			}
			else
			{
				while(current2->next!=NULL)
				{
					current2=current2->next;
				
				}
				current2->next=newnode2;
			}
   }
	
}
void delete_linked(struct node **top,struct node **top2 )
{
	if(*(top2)!=NULL)
	{
			struct node *currnode;
			if(*(top2)==NULL)
			{
				printf("\n Q Linked List is  Empty ");
			}
			else
			{		
					currnode=*(top2);
				*(top2)=currnode->next;
		
				printf("\n Delete Value is :- %d ",currnode->data);
				printf("\n ");
				free(currnode);
			}
   }
   else
   {
   	       struct node *currnode2;
			if(*(top)==NULL)
			{
				printf("\n Q Linked List is  Empty ");
			}
			else
			{
				currnode2=*(top);
				*(top)=currnode2->next;
		
				printf("\n Delete Value is :- %d ",currnode2->data);
				printf("\n ");
				free(currnode2);
			}
   }	
	
}
void display_linked(struct node **top ,struct node **top2 )
{
	

		struct node *current;
			struct node *current2;
		current=*(top2);
		printf("seniour Queue");
		if(current==NULL)
		{
				printf("\n  Q Linked List is Empty");
		}
		else
		{
			while(current!=NULL)
			{
				printf("\n Display Value is %d ",current->data);
				current=current->next;
			}
		}
		printf("\n ");
        printf("juniour Queue");
    
    
		current2=*(top);
		
		if(current2==NULL)
		{
				printf("\n  Q Linked List is Empty");
		}
		else
		{
			while(current2!=NULL)
			{
				printf("\n Display Value is %d ",current2->data);
				current2=current2->next;
			}
		}
		printf("\n ");
	
}
