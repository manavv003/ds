//pract - 9 allocate memory for atlest 10 students which contain memory to stor atlest 15 character using pointer 
#include<stdio.h>
void main()
{
	char *name[15];
	int i;
	for(i=0;i<10;i++)
	{
		name[i]=(char *)malloc(sizeof(char)*15);
		printf("Enter Student name : ");
		scanf("%s",name[i]);
	}
	
	for(i=0;i<10;i++)
	{
		printf("Student name : ");
		printf("%s\n",name[i]);
	}
}
