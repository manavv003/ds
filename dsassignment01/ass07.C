#include <stdio.h>
#include<conio.h>
#define size 5  
int deque[size];    
int f = -1, r = -1;    

void insert_front()
{
    int x;
    if((f==0 && r==size-1) || (f==r+1))
    {
	    printf("Queue is full");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&x);

        if((f==-1) && (r==-1))
        {
	    	f=0;
	    	r=0;
            deque[f]=x;
        }
		else if(f==0)    
		{    
			f=size-1;    
			deque[f]=x;    
		}    

		else
		{
			f=f-1;
			deque[f]=x;
		}
    }

	
}


void insert_rear()
{
    int x;
    if((f==0 && r==size-1) || (f==r+1))
    {
	    printf("Queue is full");
    }
    else
    {
		printf("Enter data: ");
		scanf("%d",&x);

		if((f==-1) && (r==-1))
		{
			r=0;
			deque[r]=x;
		}
		else if(r==size-1)    
		{    
			r=0;    
			deque[r]=x;    
		}    

		else
		{
			r++;
			deque[r]=x;
		}
    }

}


void display()
{
    if(f==-1 && r==-1)
    {
		printf("Deque is empty");
    }
    else
    {
		int i=f;
		printf("\nElements in a deque are: ");

		while(i!=r)
		{
			printf("%d-> ",deque[i]);
			i=(i+1)%size;
		}
       printf("%d->",deque[r]);
     }
}




void delete_front()
{
    if(f==-1 && r==-1)
    {
	printf("Deque is empty");
    }
    else if(f==r)
    {
	printf("\nThe deleted element is %d", deque[f]);
	f=-1;
	r=-1;

    }
     else if(f==(size-1))
     {
	 printf("\nThe deleted element is %d", deque[f]);
	 f=0;
     }
     else
     {
	  printf("\nThe deleted element is %d", deque[f]);
	  f=f+1;
     }
}

void delete_rear()
{
    if((f==-1) && (r==-1))
    {
	printf("Deque is empty");
    }
    else if(f==r)
    {
	printf("\nThe deleted element is %d", deque[r]);
	f=-1;
	r=-1;

    }
     else if(r==0)
     {
	 printf("\nThe deleted element is %d", deque[r]);
	 r=size-1;
     }
     else
     {
	  printf("\nThe deleted element is %d", deque[r]);
	  r=r-1;
     }
}

void main()
{

        int choice;

    do
    {
	
	printf("\n1.Innsert_front \n2.Innsert_rear \n3.delete_front  \n4.delete_rear \n5.display \n0.End");
	
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		    insert_front();
		    getch();
		    break;

		case 2:
		    insert_rear(20);
		    getch();
		    break;

		case 3:
		    delete_front();
		    getch();
		    break;

		case 4:
		    delete_rear();
		    getch();
		    break;

		case 5:
		    display();
		    getch();
		    break;

		case 0:
		    exit(0);
		    break;

	default:
	    printf("\nplease Enter valid choice..");
	}
    } while(1);
   
}