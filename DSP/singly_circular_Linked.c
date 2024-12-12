// Write  menu driven program to implement singly circular Linked List of 1)  insert 2) delete 3) Modify 4) Display.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	
	int data;
	struct node *next;
};
 
void main()
{
	void insert_Circular_link(struct node **, int );
	void delete_link(struct node **,int search);
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
					insert_Circular_link(top,val);
					break;
			   }
		case 2:{
					printf("\n Enter Search Value: - ");
					scanf("%d",&search);
					delete_link(top,search);	
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
void insert_Circular_link(struct node **top, int val)
{
	struct node *newnode,*curr,*pre;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	pre = NULL;
	curr = *(top);
	newnode->data=val;
	
	if ( curr == NULL)
	{
		newnode->next = newnode;
		*(top) = newnode;
	}
	else
	{
		
		if(curr->data>val)
		{
		
				while( curr->next != *(top) )
				{  
				  curr = curr->next;
				} 
				
				curr->next=newnode;
				newnode->next=*(top);
				*(top)=newnode;
		}
		else
		{
				while( curr->next != *(top) && curr->next->data < val)
				{  
				  curr = curr->next;
				} 
					newnode->next = curr->next;
					curr->next = newnode;
		
		}
		
		printf("\n");
	}	
}
void delete_link(struct node **top , int search)
{
		struct node *curr, * pre;
		pre = NULL;
		curr = *(top);
		
		if(curr == NULL)
		{
			printf("\n Linked List is  Empty ");
		}
		else
		{
			
			if(curr->data==search)
			{
				if(curr->next!=*(top))
				{
					pre = curr;
					curr = curr->next;
				
					while(curr->next!=*(top))
					{
						curr = curr->next;
					}
					
					curr->next = pre ->next;
					*(top)= pre->next;
					
					printf("\n Delete Value is :- %d ",pre->data);
					
					free(pre);
				}
				else
				{
					*(top)=NULL;
					printf("\n Delete Value is :- %d ",curr->data);
					printf("\n ");
					free(curr);
				}	
			}
			else
			{
				while(curr->next!=*(top) && curr->data!=search)
				{
					pre = curr;
					curr = curr->next;
				}
				if(curr->next==*(top) && curr->data!=search)
					printf("\n Element Not Found :");
				else	
				{
					pre->next=curr->next;
					
					printf("\n Delete Value is :- %d ",curr->data);
					printf("\n ");
					free(curr);
				}			
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
		
		while(current->next!=*(top))
		{
			
			printf("\n Display Value is %d ",current->data);
			current=current->next;
		}	
			printf("\n Display Value is %d ",current->data);
		
	}
	printf("\n ");
}
