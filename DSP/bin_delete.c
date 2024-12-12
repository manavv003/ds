//program 10 - binary tree with delete
#include<stdio.h>
#include<stdlib.h>

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
	void bst_tra(struct treenode **,int );
	void bst_del(struct treenode **,int );
	
	struct treenode **root, *head;
	int val,search;
	int choice;
	
	root=(struct treenode **)malloc(sizeof(struct treenode *));
	*(root)=NULL;
		
	while(1)
	{
		printf("\n 1.Insert : ");
		printf("\n 2.Inorder Traverse : ");
		printf("\n 3.Preorder Traverse : ");
		printf("\n 4.Postorder Traverse : ");
		printf("\n 5.BTS Traverse : ");
		printf("\n 6.BTS Delete : ");
		printf("\n 7.exit : ");
		printf("\n Enter choice : ");
		scanf("%d",&choice);
		printf("\n ");
		switch(choice)
		{
			case 1:{
					printf("\n Enter value :");
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
	    			printf("\n Enter Display Search Value : ");
	    			scanf("%d",&search);
					bst_tra(root,search);
					break;
			   	}
			case 6:{
	    			printf("\n Enter Delete Search Value : ");
	    			scanf("%d",&search);
					bst_del(root,search);
					break;
			   	}
			case 7:{
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
		return;
	inorder_tra(curr->left);
	printf("\n Inorder Traverse %d ", curr->data);
	inorder_tra(curr->right);	
}
void preorder_tra(struct treenode *curr)
{	
	if(curr == NULL)
		return;
	printf("\n PreOrder Traverse %d ", curr->data);
	preorder_tra(curr->left);
	preorder_tra(curr->right);	
}
void postorder_tra(struct treenode *curr)
{
	if(curr == NULL)
		return;
	postorder_tra(curr->left);
	postorder_tra(curr->right);
	printf("\n PostOrder Traverse %d ", curr->data);	
}
void bst_tra(struct treenode **root , int search)
{	
	struct treenode *curr,*pre;
	curr = *(root);
	pre = NULL;
	
	if(curr == NULL)
	{
		printf("\n Binary Search Traverse is Empty...");
	}			
	else
	{
		while(curr!=NULL && curr->data != search)
		{
			pre = curr;
			if(curr->data < search )
			{
				if(curr->right==NULL)
					curr=NULL;
				else		
					curr = curr->right ;
			}
			else
			{
				if(curr->left==NULL)
					curr=NULL;
				else	
					curr = curr->left;
			}	
		}
		if(curr==NULL && pre->data != search)
		{
			printf("\n Binary Search Traverse not Found is %d ",search);
		}
		else
		{
			printf("\n Binary Search Traverse  Found is %d ",curr->data);	
		}	
	}	
}
void bst_del(struct treenode **root , int search)
{	
	struct treenode *curr,*pre ,*prev , *parent,*Q;
	char D;
	int found=0;
	curr = *(root);
	Q=NULL;
	pre = NULL;
	prev = NULL;
	parent = NULL;
	
		while(!found && curr!=NULL)
		{	
			if(curr->data==search )
			{
				found=1;
			}
			else
			{
				if(curr->data>search)
				{
					parent=curr;
					curr=curr->left;
					D='L';
				}
				else
				{
					parent=curr;
					curr=curr->right;
					D='R';
				}
			}
		}
		if(!found)
		{
			printf("\n Not Found ");
		}
		else
		{
			if(curr->left==NULL && curr->right==NULL)
		   	{
				Q=NULL;			
			}
		   else
			{
			    if( (curr->left!=NULL && curr->right==NULL) || (curr->left==NULL && curr->right!=NULL))
				{
					if(curr->left == NULL)
					{
						Q=curr->right;		
						}
						else
						{
							Q=curr->left;
						}	
					}
					else
					{
						pre=curr->right;
						prev=pre->left;
						if(prev==NULL)
						{
							Q=pre;
							pre->left=curr->left;
						}
						else
						{
							while(prev->left!=NULL)
							{
								pre=prev;
								prev=prev->left;
							}
							pre->left=prev->right;
							prev->left=curr->left;
							prev->right=curr->right;
							Q=prev;
						}
	                }
               	}
               	free(curr);
           	}
           	if(D=='L')
		   	{
		   		parent->left=Q;
		   	}
		   	else if(D=='R')
		   	{
		   		parent->right=Q;
		   	}
		   	else
		   	{
		   		*(root)=Q;
			}
}
