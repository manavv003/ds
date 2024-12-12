// Write a menu driven program to implement double stack  1) Push 2) Pop 3) Display.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 10
int s[max];

void main()
{
	
	void push_doub_stk1( int * , int * , int );
	void push_doub_stk2( int * , int * , int );
	void pop_doub_stk( int * , int * ); 
	void disp2( int *,int *);
	
	int *top1 , *top2;
	
	int ele,choice ;
	
	top1= (int *)malloc(sizeof(int *));
	top2 = (int *)malloc(sizeof(int));
	
	*(top1) = (max/2)-1;
	*(top2) = max/2;
	
	while(1)
	{
		printf("\n 1.Push Front :-  ");
		printf("\n 2.Push Last :-  ");
		printf("\n 3.Pop Value :-  ");
		printf("\n 4.Disp Value :-  ");
		printf("\n 5.Exit:-  ");
		
		printf("\n Enter Your Choice :- ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:{
				printf("\n Enter Front Value :");
				scanf("%d",&ele);
				push_doub_stk1(top1,top2,ele);
				break;
			}
			case 2:{
				printf("\n Enter Last Value :");
				scanf("%d",&ele);
				push_doub_stk2(top1,top2,ele);
				break;
			}
			case 3:{
				pop_doub_stk(top1,top2);
				break;
			}
			case 4:{
				disp2(top1,top2);
				break;
			}
			case 5:{
				exit(1);
				break;
			}
			
		}
		
	}
	
}

void push_doub_stk1( int *top1 , int *top2 , int ele)
{
	if(*(top1)==-1)
	{
		printf("\n Front Stack is Full ...");
	}
	else
	{
		s[*(top1)] = ele;	
		*(top1) = *(top1)-1;
		
	}
}
void push_doub_stk2(int *top1 , int *top2 , int ele)
{
		int val;
		val = ele;
		if(*(top2)==max)
		{
			printf("\n End Stack is Full ...");	
		}
		else
		{
			s[*(top2)] = ele;
			*(top2) = *(top2) + 1;
			
		}
}
void pop_doub_stk(int *top1 , int *top2)
{
	int temp , choice ;
	
	if((*(top1)==(max/2)-1) && (*(top2) == max/2 ))
	{
		printf("\n Double Stack is Empty ...");
	}
	else
	{
		printf("\n 1. Pop in Front Element ... \n 2 .Pop in Last Element ... \n 3. Exit ... ")	;
		printf("\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				if(*(top1)!=(max/2)-1)
				{
					temp = s[*(top1)];
					*(top1) = *(top1)+ 1;
				//	printf ("\n Front Element Pop Value is %d", temp);
				}
				else{
					printf("\n Front side Element is Empty ... ");
				}
			
				break;
			}
			case 2:{
				if(*(top2) == max/2)
				{
					printf("\n End side Element is Empty...");
				}
				else
				{
						temp = s[*(top2)];
						*(top2) = *(top2) - 1;
					
				}
			
				break;
			}
			
			case 3:{
				exit(1);
				break;
			}
			default :{
				printf("\n Invalid Choice ...");
			}
		}
	}
}
void disp2(int *top1,int *top2)
{
	int i,j,choice;
	
	if(*(top1)==(max/2)-1 && *(top2) == max/2)
	{
		printf("\n Double Stack is Empty ...");
	}
	else
	{
		printf("\n 1. Display in Front Element ... \n 2 .Display in Last Element ... \n 3. Exit ... ")	;
		printf("\n Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				
					for(i=(*(top1)+1) ; i< *(top2) ; i ++ )
					{
						printf("\n Front Element Display is ...  %d",s[i]);
					}
				
				break;
			}
			case 2:{
				
					for(j=(*(top2)-1) ; j> *(top1)  ; j -- )
					{
						printf("\n End Element Display is ...  %d",s[j]);
					}
			
			
				break;
			}
			
			case 3:{
				exit(1);
				break;
			}
			default :{
				printf("\n Invalid Choice ...");
			}
		}
	}
	
}
