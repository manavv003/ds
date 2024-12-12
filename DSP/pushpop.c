//pract - 1 Write a programme to Implementation of Stack
#include<stdio.h>
int st[5];
int top=-1;
void main()
{
	void push(int ele);
	int pop();
	int peep();
	void display();
	
	int ele,choice,Peek,del;
	while(choice!=5)
	{
		printf("\n 1. Push ");
		printf("\n 2. pop ");
		printf("\n 3. peek ");
		printf("\n 4. display ");
		
		printf("\n enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("push no: ");
					scanf("%d",&ele);
					push(ele);
					break;
			case 2: del=pop();
					printf("Remove No: %d",del);
					break;
			case 3: Peek=peek();
					break;
			case 4: display();
					break;
			default: printf("enter currect choice");		
		
		}
	}
}
void push(int ele)
{
	if(top>=4)
	{
		printf("stack is overflow ");	
	}
	else
	{
		top++;
		st[top]=ele;
	
	}
}
int pop()
{
	int del;
	if(top==-1)
	{
		printf("stack is underflow");
	}
	else
	{
		del=st[top];
		top--;	
	}
	return del;
}
int peek()
{
	printf("peek no: %d",st[top]);
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d",st[i]);
		printf("\n");
	}
}
