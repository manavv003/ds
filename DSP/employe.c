//Emp Pro Test 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int no;
	char name[10];
	int sal;
	struct node *next;
};

void main()
{
	void insert(struct node **,int,char [10]  ,int);
	void dislplay(struct node **);

	struct node **top;
	char name[10];
	int no , sal ,choice ;
	
	top = (struct node **)malloc(sizeof(struct node));
	*(top)=NULL;

	while(1)
	{
		printf("\n 1. Insert ");
		printf("\n 2. display ");
		printf("\n 3. exit ");
		
		printf("\n Enter the choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter the Emp No :- ");
				scanf("%d",&no);
				printf("\n Enter the Emp Name :- ");
				scanf("%s",&name);
				printf("\n Enter the Emp sal :- ");
				scanf("%d",&sal);
				insert(top,no,name,sal);
				break;

			case 2:
				dislplay(top);
				break;

			case 3:
				exit(1);
				break;

			default:
				printf("Invalid choice");
				break;
		}
	}
}

void insert(struct node **top,int no, char name[10],int sal)
{
	struct node *newnode,*curr,*pre;
	newnode = (struct node *)malloc(sizeof(struct node));
	curr = *(top);
	pre = NULL;
	newnode->no = no;
	newnode->sal = sal;
	strcpy(newnode->name,name);
	
	//	newnode->next =NULL;
	
	if(curr==NULL)
	{
		newnode->next =NULL;
		*(top)=newnode;
	}
	else
	{
		while( curr != NULL && curr->sal < sal)
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

void dislplay(struct node **top)
{
	struct node *curr;

	curr=*(top);
	if(curr == NULL)
	{
		printf("\n Emp list is empty ");
	}
	else
	{
		while(1)
		{
			printf("\n Emp No : %d",curr->no);
			
			printf("\n Emp Name : %s",(curr->name));
			
			printf("\n Emp Sal : %d",curr->sal);
			
			if(curr->next == NULL)
			   break;
			curr = curr->next;
		}
		printf("\n");
	}
}
