//program 16- Radix Sort
#include<stdio.h>
int largest(int a[],int n);
void r_sort(int a[],int n);

void main(){

	int a[10],i,n;

	printf("Enter the Number : ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	r_sort(a,n);

	for(i=0;i<n;i++){	
		printf("%d\n",a[i]);
	}
}

int largest(int a[10],int n){

	int large=a[0],i;

	for(i=1;i<n;i++){
		
		if(a[i]>large){	
			large=a[i];
		}
		return large;
	}
}

void r_sort(int a[10],int n){
	
	int bucket[10][10],bucket_count[10];
	int i,j,k,remainder,nop=0,divisor=1,large,pass;
	large=largest(a,n);

	while(large>0){	
		nop++;
		large/=10;
	}

	for(pass=0;pass<nop;pass++){s
		for(i=0;i<10;i++){	
			bucket_count[i]=0;
		}

		for(i=0;i<10;i++){		
			remainder=(a[i]/divisor)%10;
			bucket[remainder][bucket_count[remainder]]=a[i];
			bucket_count[remainder]+=1;
		}
		i=0;

		for(k=0;k<10;k++){	
			for(j=0;j<bucket_count[k];j++){
				a[i]=bucket[k][j];
				i++;
			}
		}
		divisor *=10;
	}
}
