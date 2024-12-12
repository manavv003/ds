//pract - 14 bubble sort
#include<stdio.h>
int main(){
   	int a[50], i,j,n,temp;
	printf("enter the elements in the list");
   	scanf("%d",&n);
   
   	for(i=0; i<n; i++){
   		printf("enter the elements:");
      	scanf ("%d", &a[i]);
   	}
   
   	printf("Before bubble sorting the elements are: \n");
   	for(i=0; i<n; i++)
     	printf("%d \t", a[i]);
   	for (i=0; i<n-1; i++){
      	for (j=i+1; j<n; j++){
        	if (a[i] > a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         	}
      	}
   	}
   
   	printf ("\n after bubble sorting the elements are: \n");
   	for (i=0; i<n; i++)
      	printf("%d\t ", a[i]);
   	return 0;
}

