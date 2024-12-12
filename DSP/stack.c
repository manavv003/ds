#include<stdio.h>
#define max 10
int s[max];
void main()
{
	int ele,del,ch;
	int *top;
	
	void push(int *top,int ele);
	int pop(int *top);
	void peak(int *top);
	void display(int *top);
	
	top=(int *)malloc(sizeof(int));
	*top=-1;
	while(1){
		printf("1. push");
		printf("\n 2. pop");
		printf("\n 3. peak");
		printf("\n 4. display");
		
		printf("\n enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("enter element ");
					scanf("%d",&ele);
					push(top,ele);
					break;
			case 2:	del=pop(top);
					break;
			case 3:	peak(top);
					break;
			case 4:	display(top);
					break;
		}
	}
}
void push(int *top,int ele)
{
	if(*top>=max-1)
	{
		printf("stack is full");
	}
	else{
		(*top)=(*top)+1;
		s[(*top)]=ele;
	}
}
int pop(int *top)
{
	int remove;
	if(*top==-1)
	{
		printf("stack is empty");
	}
	else{
		remove=s[(*top)];
		(*top)=(*top)-1;
	}
	return 0;
}
void peak(int *top)
{
	printf("top value %d :",s[(*top)]);
}
void display(int *top)
{
	int i;
	for(i=0;i<=(*top);i++)
	{
		printf("%d \n",s[i]);
	}
}

