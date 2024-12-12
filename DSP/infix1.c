//pract-2 infix to postfix using one oparator(single argument)
#include<stdio.h>
#define max 10
char st[5];
char ch;
int top=-1;
void push();
char pop();
void main()
{
	printf("enter a char ends with $ = ");
	scanf("%c",&ch);
	do
	{
		if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' )
		{
			printf("%c",ch);
		}
		else
		{
			push(ch);
		}
		scanf("%c",&ch);
	}
	while(ch!='$');
	ch=pop();
	printf("%c",ch);
}
void push()
{
	if(top>=max-1)
	{
		printf("stack is overflow");
	}
	else
	{
		top++;
		st[top]=ch;
	}
}
char pop()
{
	char temp;
	if(top>=0)
	{
		temp=st[top];
		top--;
	}
	else
	{
		printf("stack is underflow");
	}
	return (temp);
}

