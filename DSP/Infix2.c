//pract - 3 infix to postfix two different operator.........................
#include<stdio.h>
#define max 10
char stack[10];
char ch,chr;
int top=-1;
void push();
char pop();
int prec();
void main()
{
	printf("Enter Infix data with (dollar sign) $ : ");
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
				if(prec()<=1)
				{
					chr=pop();
				    printf("%c",chr);
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
	stack[++top]=ch;
}
char pop()
{
	if(top>=-1)
	{
		return stack[top--];
	}
}
int prec()
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
