//pract-4 infix to postfix using one oparator(single argument) with precedence
#include<stdio.h>
#include<stdio.h>
#define max 10
char stack[10];
char ch,cch;
int top=-1;
void push();
char pop();
int pre();
void main()
{
	printf("Enter your data that ends with $ = ");
	scanf("%c",&ch);
	 do
	 {
	 	if(ch>='A' && ch<='Z' || ch>='a' && ch<='z') 
	 	{
	 		printf("%c",ch);
	    }
	    else
	    {
	    	if(top==-1)
	    	{
	    		push(ch);
	    		
			}
			else
			{
				if(pre()<=1)
				{
					cch=pop();
				    printf("%c",cch);
			     	push(ch);
				}
				else
				{
					push(ch);
				}
			
			}
	    
		}
		scanf("%c",&ch);
	 }while(ch!='$');
	while(top!=-1)
	{
		 ch=pop();
	     printf("%c",ch);
	}
	
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
		stack[top]=ch;
	}
}
char pop()
{
	char temp;
	if(top>=0)
	{
		temp=stack[top];
		top--;
	}
	else
	{
		printf("stack is underflow");
	}
	return (temp);
}
int pre()
{
	if(ch=='+' || ch=='-')
	{
		return (1);
	}
	 if(ch=='*' || ch=='/') 
	{
		return (2);
	}
}
