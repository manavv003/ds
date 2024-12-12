// write menu driven program to implement binary tree of integers
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct treenode
{
	struct treenode *left;
	int data;
	struct treenode *right;
};
 
void main()
{
	void insert_binarytree_link(struct treenode **, int );
	void inorder_tra(struct treenode *);
	void preorder_tra(struct treenode *);
	void postorder_tra(struct treenode *);
	
	struct treenode **root, *head;
	int val;
	int choice;
	
	root=(struct treenode **)malloc(sizeof(struct treenode *));
	*(root)=NULL;
	
	
	while(1)
	{
		printf("\n 1.Insert :- ");
		printf("\n 2.Inorder Traverse :- ");
		printf("\n 3.Preorder Traverse :- ");
		printf("\n 4.Postorder Traverse :- ");
		printf("\n 5.Exit :- ");
		printf("\n Enter choice :- ");
		scanf("%d",&choice);
		printf("\n ");
		switch(choice)
		{
		case 1:{
					printf("\n Enter value :-");
					scanf("%d",&val);
					insert_binarytree_link(root,val);
					break;
			   }		
		case 2:{
					head=*(root);
					inorder_tra(head);
					break;
			   }
		case 3:{
					head=*(root);
					preorder_tra(head);
					break;
			  }
		case 4:{
					head=*(root);
					postorder_tra(head);
					break;
			   }
		case 5:{
				  exit(1);
				  break;
				}
		}
	}
}
void insert_binarytree_link(struct treenode **root, int val)
{
	struct treenode *newnode,*curr,*pre;
	newnode = (struct treenode *)malloc(sizeof(struct treenode));
	
	pre = NULL;
	curr = *(root);
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if ( curr == NULL)
	{
		*(root) = newnode;
	}
	else
	{
		while(curr!=NULL)
		{
			pre = curr;
			if(curr->data<val)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if(pre->data<val)
		{
			pre->right=newnode;
		}
		else
		{
			pre->left=newnode;
		}
	}	
}
void inorder_tra(struct treenode *curr)
{
	
	if(curr == NULL)
	{
		return;
	}
	inorder_tra(curr->left);
	printf("\n Inorder Traverse %d ", curr->data);
	inorder_tra(curr->right);
	
}
void preorder_tra(struct treenode *curr)
{
	
	if(curr == NULL)
	{
		return;
	}
	printf("\n PreOrder Traverse %d ", curr->data);
	preorder_tra(curr->left);
	preorder_tra(curr->right);
	
}
void postorder_tra(struct treenode *curr)
{
	
	if(curr == NULL)
	{
		return;
	}
	postorder_tra(curr->left);
	postorder_tra(curr->right);
	printf("\n PostOrder Traverse %d ", curr->data);
	
}
