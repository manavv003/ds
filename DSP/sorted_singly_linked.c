//sorted singlynlinked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void main()
{
	void insert_sort_link(struct node **, int );
	void delete_sort_link(struct node **,int );
	void display_link(struct node **);
	struct node **top;
	int val,search;
	int choice;
	top=(struct node **)malloc(sizeof(struct node *));
	*(top)=NULL;
	
	
	while(1)
	{
		printf("\n 1.Insert : ");
		printf("\n 2.delete : ");
		printf("\n 3.display : ");
		printf("\n 4.Exit : ");
		
		printf("\n Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n Enter value : ");
					scanf("%d",&val);
					insert_sort_link(top,val);
					break;
			
			case 2: printf("\n Enter Delete Search value : ");
					scanf("%d",&search);
					delete_sort_link(top,search);
					break;
			 
			case 3: display_link(top);
					break;
			 
			case 4: exit(0);
					break;
					
			default	: printf("------------Invalid Choice-----------\n");
					 break;				
	
		}
	}
}
void insert_sort_link(struct node **top, int val)
{
	struct node *newnode,*curr,*pre;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	pre = NULL;
	curr = *(top);
	newnode->data=val;
	
	if ( curr == NULL)
	{
		*(top) = newnode;
		newnode->next = NULL;
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
			 newnode->next=*(top);
			 *(top)=newnode;
		}
		else
		{
			pre->next=newnode;
			newnode->next=curr;
		}
	}
}
void delete_sort_link(struct node **top , int search)
{
	struct node *curr,*pre;
	       
	curr=*(top);
	pre=NULL;
	if(curr==NULL)
	{
		printf("Linked List Is Empty");
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
			printf("\nElement not found");
		}
		else
		{
			if(pre==NULL)
			{
				*(top)=curr->next;
			}
			else
			{
				pre->next=curr->next;
			}
			printf("\n Search Delete : %d",curr->data);	
		}	
		free(curr);
	}

}
void display_link(struct node **top)
{
	struct node *curr;
	curr=*(top);
	
	if(curr==NULL)
	{
		printf("\n Linked List is Empty");	
	}
	else
	{
		printf("Display Value :");
		while(curr!=NULL)
		{
			printf("\n%d ",curr->data);
			curr=curr->next;
		}
	}
	printf("\n ");
}
