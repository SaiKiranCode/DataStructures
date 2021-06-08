#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *fib;
	int n,i;
	printf("enter the number to find its fibonaci\n");
	scanf("%d",&n);
	fib=(int *)malloc(n*sizeof(int));
	if(fib==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	}
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	
	}
	printf("fibonacii number is %d",fib[n-1]);
	return 0;

}
