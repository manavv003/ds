#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void main()
{
	void insert_LL(struct node **,int );
	void delete_LL(struct node **);
	void display_LL(struct node **);
	
	struct node **top;
	int val,ch;
	
	top=(struct node **)malloc(sizeof(struct node *));
	*(top)=NULL;
	
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.display");
		
		printf("\nEnter Your choice");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				    printf("Enter Value :. ");
					scanf("%d",&val);
					insert_LL(top,val);
					break;
					}
			case 2:{
					delete_LL(top);
				    break;	
					}
			case 3:{
					display_LL(top);
				    break;
					}					
			case 4: exit(0);
					break;
					
			default	: printf("------------Invalid Choice-----------\n");
					 break;				
							
		}
	}	
}
void insert_LL(struct node **top,int val)
{ 
	struct node *newnode;
	
	newnode=(struct node *)malloc(sizeof(struct node ));	
	
	newnode->data=val;
	newnode->next=*(top);
	*(top)=newnode;

}
void delete_LL(struct node **top)
{
	struct node *curr;
	
	if(*(top)==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		curr=*(top);
		*(top)=curr->next;
		printf("deleted value %d",curr->data);
		free(curr);
	}
}
void display_LL(struct node **top)
{
	struct node *curr;
	curr=*(top);
	
	if(curr==NULL)
	{
		printf("\n Linked List is Empty");
	}
	else
	{
		printf("\n Display Value is:");
		while(curr!=NULL)
		{
			printf("\n%d",curr->data);
			curr=curr->next;
		}
	}
	printf("\n ");
}
