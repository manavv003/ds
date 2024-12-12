// Write  menu driven program to implement Double Linked List of 1)  insert 2) delete 3) Modify 4) Display.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	
	int data;
	struct node *prev;
	struct node *next;
};
 
void main()
{
	void insert_Doublesort_link(struct node **, int );
	void delete_search_link(struct node **,int );
	void display_link(struct node **);
	
	struct node **top;
	int val,search;
	int choice;
	
	top=(struct node **)malloc(sizeof(struct node *));
	*(top)=NULL;
	
	
	while(1)
	{
		printf("\n 1.Insert :- ");
		printf("\n 2.Search delete :- ");
		printf("\n 3.display :- ");
		printf("\n 4.Exit :- ");
		printf("\n Enter choice :- ");
		scanf("%d",&choice);
		printf("\n ");
		switch(choice)
		{
		case 1:{
					printf("\n Enter value :-");
					scanf("%d",&val);
					insert_Doublesort_link(top,val);
					break;
			   }
		
		case 2: {
					printf("\n Enter Delete Search value :-");
					scanf("%d",&search);
					delete_search_link(top,search);
					break;
				}  
		case 3:{
					display_link(top);
					break;
			   }
		case 4:{
				  exit(1);
				  break;
				}
		}
	}
}
void insert_Doublesort_link(struct node **top, int val)
{
	struct node *newnode,*curr,*pre;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	pre = NULL;
	curr = *(top);
	newnode->data=val;
	
	if ( curr == NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*(top) = newnode;
	}
	else
	{
     	while( curr != NULL && curr->data <= val)
		{  
		  pre = curr;
		  curr = curr->next;
		} 
		
		
		if(pre==NULL)
		{	
		   *(top)=newnode;
		   newnode->next=curr;
		   newnode->prev = NULL;
		   curr->prev = newnode;
		}
		else
		{
			if(curr==NULL)
			{
				newnode->prev=pre;
				pre->next=newnode;
				newnode->next=NULL;
			}
			else
			{
				newnode->next=curr;
				newnode ->prev=pre; 
				pre->next=newnode;
				curr->prev=newnode;
			}
		}
		printf("\n");
	}	
}

void delete_search_link(struct node **top , int search)
{

		struct node *curr,*pre;
		curr=*(top);
		pre=NULL;

		if(curr==NULL)
		{
			printf("\n Linked List is Empty ...");
		}

		else
		{
			while(curr!=NULL && curr->data!=search)
			{
				pre=curr;
				curr=curr->next;
			}
			if(curr==NULL)
			{
				printf("\n Element Not Found");
			}
			else
			{
				if(pre==NULL)
				{
					if(curr->next ==NULL)
					{
						*(top)=NULL;
						//free(curr);
					}
					else
					{
						*(top)=curr->next;
						curr->next->prev = curr->prev;
					}
					
				}
				else
				{
					if(curr->next ==NULL)
					{
							pre->next=NULL;
					}
					else
					{
						pre->next = curr->next;
						curr->next->prev = curr->prev;
					}
					
				}
				printf("\n Search Delete is :- %d",curr->data);
				free(curr);
			}
			
		}
}
void display_link(struct node **top)
{
	struct node *current;
	current=*(top);
	
	if(current==NULL)
		printf("\n Linked List is Empty");
	else
	{
		while(current!=NULL)
		{
			printf("\n Display Value is %d ",current->data);
			current=current->next;
		}
	}
	printf("\n ");
}
